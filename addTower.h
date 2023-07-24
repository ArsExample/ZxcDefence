#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "defaultTower.h"
#include "tile.h"

void addTower(int coordX, int coordY, std::string type, std::vector <Tower*>& towers, std::vector <Tile*>& tiles);

class TowerMgr {
public:
	std::vector <Tower*>* towers;
	std::vector <Tile*>* tiles;

	TowerMgr();
	TowerMgr(std::vector <Tower*>* _towers, std::vector <Tile*>* _tiles);
	void addTower(int coordX, int coordY, std::string type);
};