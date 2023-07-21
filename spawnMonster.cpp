#include "spawnMonster.h"

void spawnMonster(int coordX, int coordY, int pX, int pY, int bX, int bY, std::string type, int ID, std::vector <Monster*>& monsters)
{
	if (std::strcmp(type.c_str(), "default") == 0)
	{
		monsters.push_back(new DefaultMonster(coordX, coordY, pX, pY, bX, bY, ID));
	}
}