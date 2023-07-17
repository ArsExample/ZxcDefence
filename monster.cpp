#include "monster.h"

Monster::Monster()
{
	coordsInit(0, 0, 0, 0, 0, 0);
}

Monster::Monster(int coordX, int coordY, int pX, int pY, int bX, int bY) 
{
	coordsInit(coordX, coordY, pX, pY, bX, bY);
}

void Monster::coordsInit(int coordX, int coordY, int pX, int pY, int bX, int bY)
{
	relX = coordX;
	relY = coordY;
	portalX = pX;
	portalY = pY;
	baseX = bX;
	baseY = bY;

	x = ((coordX - 1) * 120) + 35;
	y = ((coordY - 1) * 120) + 35;
}