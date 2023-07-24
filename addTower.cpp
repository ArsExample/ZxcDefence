#include "addTower.h"

void addTower(int coordX, int coordY, std::string type, std::vector <Tower*>& towers, std::vector <Tile*>& tiles)
{
	if (std::strcmp(type.c_str(), "default") == 0)
	{
		std::cout << "adding tower" << std::endl;
		towers.push_back(new DefaultTower(coordX, coordY, tiles));


	}
}

TowerMgr::TowerMgr()
{

}

TowerMgr::TowerMgr(std::vector <Tower*>* _towers, std::vector <Tile*>* _tiles)
{
	towers = _towers;
	tiles = _tiles;
}

void TowerMgr::addTower(int coordX, int coordY, std::string type)
{
	if (std::strcmp(type.c_str(), "default") == 0)
	{
		std::cout << "adding tower" << std::endl;
		towers->push_back(new DefaultTower(coordX, coordY, *tiles));
	}
}