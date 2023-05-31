#include "testField.h"
#include "defaultTower.h"

int createTestField(sf::RenderWindow& window)
{
	DefaultTower t1(2, 3);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (t1.isClicked() == 1)
		{
			std::cout << "1" << std::endl;
		}

		window.clear();
		drawField(window);
		t1.update(window);
		window.display();
	}
	
	return 1;
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