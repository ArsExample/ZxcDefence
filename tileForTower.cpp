#include "tileForTower.h"

TileForTower::TileForTower(int coordX, int coordY)
{
	menu = new Menu(coordX, coordY, "new_tower");

	coordsInit(coordX, coordY);
}

void TileForTower::update(sf::RenderWindow& window, std::vector <Tower*>& towers, std::vector <Tile*>& tiles)
{
	if (clicked)
	{
		menu->open();
	}

	checkTargeted(window, sprite);

	checkClicked();

	menu->update(window);
	if (menu->towerToSpawn == "default")  // v otdel'nuyu functsiyu, no mne len'
	{
		//std::cout << "start spawning tower" << std::endl;
		addTower(relX, relY, "default", towers, tiles);
		menu->towerToSpawn = "";
	}
	window.draw(sprite);
}

void TileForTower::coordsInit(int coordX, int coordY)
{
	relX = coordX;
	relY = coordY;

	x = (coordX - 1) * 120;
	y = (coordY - 1) * 120;

	image.loadFromFile("textures/tileForTower.png");
	w = image.getSize().x;
	h = image.getSize().y;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}