#include "portal.h"

Portal::Portal(int coordX, int coordY)
{
	coordsInit(coordX, coordY);
}

void Portal::update(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Portal::coordsInit(int coordX, int coordY)
{
	relX = coordX;
	relY = coordY;

	x = (coordX - 1) * 120;
	y = (coordY - 1) * 120;

	image.loadFromFile("textures/portal.png");
	w = image.getSize().x;
	h = image.getSize().y;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}