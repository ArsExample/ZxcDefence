#pragma once
#include "tile.h"

class Base : public Tile
{
public:
	Base(int coordX, int coordY);
	void coordsInit(int coordX, int coordY);
	void update(sf::RenderWindow& window);
};