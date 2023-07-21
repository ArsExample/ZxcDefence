#include "testField.h"

int createTestField(sf::RenderWindow& window)
{
	sf::TcpSocket socket;
	if (socket.connect("192.168.1.99", 3345) != sf::Socket::Done)
	{
		std::cout << "connection error" << std::endl;
		return 0;
	}
	socket.setBlocking(false);

	std::string message = "";

	char sdata[1024];
	char rdata[1024] = { 0 };
	rdata[0] = '\0';
	std::size_t received;

	sf::Clock clock;

	int gameStarted = 0;

	std::cout << "waiting for 2nd player (1/2)" << std::endl;

	while (socket.receive(rdata, 1024, received) != sf::Socket::Done) {}

	if (strcmp(rdata, "start") == 0)
	{
		gameStarted = 1;
	}

	if (gameStarted)
	{
		Game game;
		game.addTile(2, 4);
		game.addTile(3, 4);
		game.addTile(4, 4);
		game.addTile(5, 4);
		game.addTile(6, 4);
		game.addTile(7, 4);
		game.addTile(8, 4);
		game.addTile(8, 5);
		game.addTile(8, 6);
		game.addTile(9, 6);
		game.addBase(10, 6);
		game.addTile(10, 6);
		game.addPortal(1, 4);

		game.addTower(5, 3, "default");

		//game.startWave("DDDD", 1);

		std::thread myThread(getServerInfo, std::ref(socket), std::ref(game));
		myThread.detach();

		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (game.getClickedTower() != 0)
			{
				Tower* t1 = game.getClickedTower();
				if (t1->level == 1)
				{
					t1->upgrade();
					message = "upgrade|" + std::to_string(t1->relX) + "|" + std::to_string(t1->relY);

					strncpy_s(sdata, message.c_str(), sizeof(sdata));
					socket.send(sdata, 1024);

					message = "";
					sdata[0] = '\0';
				}
				else {
					t1->downgrade();
					message = "downgrade|" + std::to_string(t1->relX) + "|" + std::to_string(t1->relY);

					strncpy_s(sdata, message.c_str(), sizeof(sdata));
					socket.send(sdata, 1024);

					message = "";
					sdata[0] = '\0';
				}
			}

			window.clear();
			drawField(window);
			game.updateAll(window, time);
			window.display();
		}
	}
	
	return 1;
}

void getServerInfo(sf::TcpSocket& socket, Game& game)
{
	char rdata[1024] = { 0 };
	rdata[0] = '\0';
	std::size_t received;
	std::string message;
	
	std::string type;
	int _x, _y;

	while (true)
	{
		if (socket.receive(rdata, 1024, received) == sf::Socket::Done)
		{
			message = rdata;
			std::cout << "Received " << rdata << std::endl;
			
			type = split(rdata, '|')[0];

			if (strcmp(type.c_str(), "upgrade") == 0)
			{
				_x = std::stoi(split(rdata, '|')[1]);
				_y = std::stoi(split(rdata, '|')[2]);

				std::cout << "trying to upgrade" << std::endl;
				if (game.getTowerByCoords(_x, _y) != 0)
				{
					game.getTowerByCoords(_x, _y)->upgrade();
				}
				else
				{
					std::cout << "nullptr error" << std::endl;
				}
				//_tower.upgrade();
			}
			else if (strcmp(type.c_str(), "downgrade") == 0)
			{
				_x = std::stoi(split(rdata, '|')[1]);
				_y = std::stoi(split(rdata, '|')[2]);

				std::cout << "trying to downgrade" << std::endl;
				if (game.getTowerByCoords(_x, _y) != 0)
				{
					game.getTowerByCoords(_x, _y)->downgrade();
				}
				else
				{
					std::cout << "nullptr error" << std::endl;
				}
			}
			else if (strcmp(type.c_str(), "wave") == 0)
			{
				std::string monstersStr = split(rdata, '|')[1];
				int waveNumber = stoi(split(rdata, '|')[2]);

				game.startWave(monstersStr, waveNumber);
			}

			rdata[0] = '\0';
			message = "";

		}
	}
}

int i;

void drawField(sf::RenderWindow& window)
{
	for (i = 0; i < 15; i++)
	{
		sf::Vertex line[] =
		{
		 sf::Vertex(sf::Vector2f(i * 120 + 120, 0)),
		 sf::Vertex(sf::Vector2f(i * 120 + 120, 1080))
		};

		window.draw(line, 2, sf::Lines);
	}

	for (i = 0; i < 8; i++)
	{
		sf::Vertex line[] =
		{
		 sf::Vertex(sf::Vector2f(0, i * 120 + 120)),
		 sf::Vertex(sf::Vector2f(1920, i * 120 + 120))
		};

		window.draw(line, 2, sf::Lines);
	}
}