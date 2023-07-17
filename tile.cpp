#include "tile.h"

Tile::Tile()
{
	coordsInit(0, 0);
}

Tile::Tile(int coordX, int coordY)
{
	coordsInit(coordX, coordY);
}

void Tile::update(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Tile::coordsInit(int coordX, int coordY)
{
	relX = coordX;
	relY = coordY;

	x = (coordX - 1) * 120;
	y = (coordY - 1) * 120;

	image.loadFromFile("textures/tile.png");
	w = image.getSize().x;
	h = image.getSize().y;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

int Tile::getX()
{
	return relX;
}

int Tile::getY()
{
	return relY;
}