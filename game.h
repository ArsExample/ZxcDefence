#pragma once
#include <vector>
#include <string>

#include "defaultTower.h"
#include "portal.h"
#include "base.h"
#include "getTile.h"
#include "tileForTower.h"
#include "shoot.h"
#include "addTower.h"
#include "spawnMonster.h"
#include "wave.h"

class Game {
public:
	Wave waveMgr;

	std::vector <Tower*> towers;
	std::vector <Tile*> tiles;
	std::vector <TileForTower*> tilesFt;
	std::vector <Portal*> portals;
	std::vector <Base*> bases;
	std::vector <Monster*> monsters;
	std::vector <Bullet*> bullets;

	//TowerMgr towerMgr;

	Game();
	void startWave(std::string _wave, int waveNumber);
	void createTower(int coordX, int coordY, std::string type);
	void addTile(int coordX, int coordY);
	void addTileForTower(int coordX, int coordY);
	void addPortal(int coordX, int coordY);
	void addBase(int coordX, int coordY);
	void addMonster(int coordX, int coordY, int pX, int pY, int bX, int bY, std::string type, int ID);
	void deleteMonster(Monster* _monster);
	void deleteBullet(Bullet* _bullet);
	void updateAll(sf::RenderWindow& window, float time);
	Tower* getTowerByCoords(int x, int y);
	Tower* getClickedTower();
	Portal* getPortal(int id);
	Base* getBase(int id);
};