#include "base.h"

Base::Base(int coordX, int coordY)
{
	coordsInit(coordX, coordY);
}

void Base::update(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Base::coordsInit(int coordX, int coordY)
{
	relX = coordX;
	relY = coordY;

	x = (coordX - 1) * 120;
	y = (coordY - 1) * 120;

	image.loadFromFile("textures/base.png");
	w = image.getSize().x;
	h = image.getSize().y;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}