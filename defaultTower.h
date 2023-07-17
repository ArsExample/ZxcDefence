#pragma once
#include "tower.h"

class DefaultTower: public Tower
{
public:
	DefaultTower(int coordX, int coordY);
	void coordsInit(int coordX, int coordY);
	void upgrade();
	void downgrade();
	void attack();
	void fullDraw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	void ttlSync();
};