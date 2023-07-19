#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "monster.h"

class Bullet {
public:
	int x, y, w, h, relX, relY, speed;
	float tX, tY, dX, dY, angle, sX, sY;
	bool wannadie;
	Monster* target;
	
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	Bullet();
	Bullet(int coordX, int coordY);
	void coordsInit(int coordX, int coordY);

	virtual void update(sf::RenderWindow& window, float time) = 0;
	virtual void fullDraw(sf::RenderWindow& window) = 0;
	virtual void move(float time) = 0;
	virtual void die() = 0;
};