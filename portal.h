#pragma once
#include "tile.h"

class Portal : public Tile 
{
public:
	Portal(int coordX, int coordY);
	void coordsInit(int coordX, int coordY);
	void update(sf::RenderWindow& window);
};