#include "tower.h"

Tower::Tower()
{
	coordsInit(0, 0);
}

Tower::Tower(int coordX, int coordY, std::vector <Tile*> allTiles)
{
	coordsInit(coordX, coordY);
}

void Tower::coordsInit(int coordX, int coordY)
{
	relX = coordX;
	relY = coordY;

	x = (coordX - 1) * 120;
	y = (coordY - 1) * 120;
}