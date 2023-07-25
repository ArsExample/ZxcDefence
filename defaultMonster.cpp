#include "defaultMonster.h"

DefaultMonster::DefaultMonster(int coordX, int coordY, int pX, int pY, int bX, int bY, int ID)
{
	id = ID;

	coordsInit(coordX, coordY, pX, pY, bX, bY);

	speed = 1;
	health = 2;

	deltaX = 0;
	deltaY = 0;
	wannadie = false;
}

void DefaultMonster::update(sf::RenderWindow& window, float time, std::vector <Tile*> tiles, int& moneyBalance)
{
	if (health > 0)
	{
		fullDraw(window);
		move(tiles, time, moneyBalance);
	}
	else 
	{
		die(moneyBalance);
		addMoney(moneyBalance, 10);
	}
}

void DefaultMonster::fullDraw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void DefaultMonster::move(std::vector <Tile*> tiles, float time, int& moneyBalance)
{
	if (relX == portalX && relY == portalY)  // esli v taile portala
	{
		try {
			if (getTileByCoords(relX + 1, relY, tiles) != 0)
			{
				prevX = sprite.getPosition().x;
				sprite.move(0.1 * time, 0);
				deltaX += sprite.getPosition().x - prevX;
				if (deltaX >= 120)
				{
					prevRelX = relX;
					relX += 1;
					deltaX = 0;
				}
			}
			else {
				try
				{
					if (getTileByCoords(relX - 1, relY, tiles) != 0)
					{
						prevX = sprite.getPosition().x;
						sprite.move(-0.1 * time, 0);
						deltaX += prevX - sprite.getPosition().x;
						if (deltaX >= 120)
						{
							prevRelX = relX;
							relX -= 1;
							deltaX = 0;
						}
					}
					else
					{
						try
						{
							if (getTileByCoords(relX, relY + 1, tiles) != 0)
							{
								prevY = sprite.getPosition().y;
								sprite.move(0, 0.1 * time);
								deltaY += sprite.getPosition().y - prevY;
								if (deltaY >= 120)
								{
									prevRelY = relY;
									relY += 1;
									deltaY = 0;
								}
							}
							else {
								try
								{
									if (getTileByCoords(relX, relY - 1, tiles) != 0)
									{
										prevY = sprite.getPosition().y;
										sprite.move(0, -0.1 * time);
										deltaY += prevY - sprite.getPosition().y;
										if (deltaY >= 120)
										{
											prevRelY = relY;
											relY -= 1;
											deltaY = 0;
										}
									}
								}
								catch (const std::exception&)
								{
									std::cout << "PROBABLY array out of bounds exception in 'defaultMonster.cpp/move()'" << std::endl;
								}
							}
						}
						catch (const std::exception&)
						{
							std::cout << "PROBABLY array out of bounds exception in 'defaultMonster.cpp/move()'" << std::endl;
						}
					}
				} catch (const std::exception&) {
					std::cout << "PROBABLY array out of bounds exception in 'defaultMonster.cpp/move()'" << std::endl;
				}
			}
		}
		catch (const std::exception&)
		{
			std::cout << "PROBABLY array out of bounds exception in 'defaultMonster.cpp/move()'" << std::endl;
		}
	}
	else if (relX == baseX && relY == baseY) {  // esli v taile bazy
		std::cout << "in base" << std::endl;
		die(moneyBalance);
	}
	else {  // esli na doroge
		try {
			if (getTileByCoords(relX + 1, relY, tiles) != 0 && (getTileByCoords(relX + 1, relY, tiles)->relX != prevRelX))
			{
				prevX = sprite.getPosition().x;
				sprite.move(0.1 * time, 0);
				deltaX += sprite.getPosition().x - prevX;
				if (deltaX >= 120)
				{
					prevRelX = relX;
					prevRelY = relY;
					relX += 1;
					deltaX = 0;
				}
			}
			else {
				try
				{
					if (getTileByCoords(relX, relY + 1, tiles) != 0 && (getTileByCoords(relX, relY + 1, tiles)->relY != prevRelY))
					{
						prevY = sprite.getPosition().y;
						sprite.move(0, 0.1 * time);
						deltaY += sprite.getPosition().y - prevY;
						if (deltaY >= 120)
						{
							prevRelX = relX;
							prevRelY = relY;
							relY += 1;
							deltaY = 0;
						}
					}
					else
					{
						try
						{

							//std::cout << (getTileByCoords(relX - 1, relY, tiles) != 0) << std::endl;
							/*if (getTileByCoords(relX - 1, relY, tiles) != 0)
							{
								std::cout << "my relX: " << relX << " tile relX: " << getTileByCoords(relX - 1, relY, tiles)->relX << " prev relX: " << prevRelX << std::endl;
								std::cout << (getTileByCoords(relX - 1, relY, tiles)->relX != prevRelX) << std::endl;
							}*/

							if (getTileByCoords(relX - 1, relY, tiles) != 0 && (getTileByCoords(relX - 1, relY, tiles)->relX != prevRelX))
							{
								std::cout << "going left" << std::endl;

								prevX = sprite.getPosition().x;
								sprite.move(-0.1 * time, 0);
								deltaX += prevX - sprite.getPosition().x;
								if (deltaX >= 120)
								{
									prevRelX = relX;
									prevRelY = relY;
									relX -= 1;
									deltaX = 0;
								}
							}
							else {
								try
								{
									if (getTileByCoords(relX, relY - 1, tiles) != 0 && (getTileByCoords(relX, relY - 1, tiles)->relY != prevRelY))
									{
										prevY = sprite.getPosition().y;
										sprite.move(0, -0.1 * time);
										deltaY += prevY - sprite.getPosition().y;
										if (deltaY >= 120)
										{
											prevRelX = relX;
											prevRelY = relY;
											relY -= 1;
											deltaY = 0;
										}
									}
								}
								catch (const std::exception&)
								{
									std::cout << "PROBABLY array out of bounds exception in 'defaultMonster.cpp/move()'" << std::endl;
								}
							}
						}
						catch (const std::exception&)
						{
							std::cout << "PROBABLY array out of bounds exception in 'defaultMonster.cpp/move()'" << std::endl;
						}
					}
				}
				catch (const std::exception&) {
					std::cout << "PROBABLY array out of bounds exception in 'defaultMonster.cpp/move()'" << std::endl;
				}
			}
		}
		catch (const std::exception&)
		{
			std::cout << "PROBABLY array out of bounds exception in 'defaultMonster.cpp/move()'" << std::endl;
		}
	}
}

void DefaultMonster::die(int& moneyBalance)
{
	std::cout << "monster#" << id << " dead" << std::endl;

	wannadie = true;
}

void DefaultMonster::coordsInit(int coordX, int coordY, int pX, int pY, int bX, int bY)
{
	relX = coordX;
	relY = coordY;
	portalX = pX;
	portalY = pY;
	baseX = bX;
	baseY = bY;

	x = ((coordX - 1) * 120) + 35;
	y = ((coordY - 1) * 120) + 35;

	image.loadFromFile("textures/defaultMonster.png");
	w = image.getSize().x;
	h = image.getSize().y;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}