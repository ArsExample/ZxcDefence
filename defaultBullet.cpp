#include "defaultBullet.h"

DefaultBullet::DefaultBullet(int coordX, int coordY, Monster* _target) 
{
	coordsInit(coordX, coordY);

	target = _target;
	speed = 1;
}

void DefaultBullet::update(sf::RenderWindow& window, float time) 
{
	move(time);
	fullDraw(window);
}

void DefaultBullet::fullDraw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void DefaultBullet::move(float time)
{
	tX = target->sprite.getPosition().x + (target->w) / 2;
	tY = target->sprite.getPosition().y + (target->h) / 2;

	dX = tX - sprite.getPosition().x;
	dY = tY - sprite.getPosition().y;
	
	angle = atan2(dY, dX);

	sX = speed * cos(angle);
	sY = speed * sin(angle);

	sprite.move(sX * time, sY * time);

	if (sprite.getGlobalBounds().intersects(target->sprite.getGlobalBounds()))
	{
		target->health -= 1;
		die();
	}
}

void DefaultBullet::die() 
{
	wannadie = true;
}

void DefaultBullet::coordsInit(int coordX, int coordY)
{
	relX = coordX;
	relY = coordY;

	x = ((coordX - 1) * 120) + 35;
	y = ((coordY - 1) * 120) + 35;

	image.loadFromFile("textures/defaultBullet1.png");
	w = image.getSize().x;
	h = image.getSize().y;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}