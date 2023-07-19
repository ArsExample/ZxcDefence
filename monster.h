#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "getTile.h"

class Monster {
public:
	int x, y, w, h, relX, relY, prevRelX, prevRelY, portalX, portalY, baseX, baseY;
	int speed, health;
	float deltaX, deltaY, prevX, prevY;
	bool wannadie;

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	Monster();
	Monster(int coordX, int coordY, int pX, int pY, int bX, int bY);
	void coordsInit(int coordX, int coordY, int pX, int pY, int bX, int bY);

	virtual void move(std::vector <Tile*> tiles, float time) = 0;
	virtual void die() = 0;
	virtual void fullDraw(sf::RenderWindow& window) = 0;
	virtual void update(sf::RenderWindow& window, float time, std::vector <Tile*> tiles) = 0;
};