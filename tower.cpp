#include "tower.h"

Tower::Tower()
{
	coordsInit(0, 0);
}

Tower::Tower(int coordX, int coordY)
{
	coordsInit(coordX, coordY);
}

void Tower::coordsInit(int coordX, int coordY)
{
	x = (coordX - 1) * 120;
	y = (coordY - 1) * 120;
}