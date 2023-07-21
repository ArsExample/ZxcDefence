#pragma once
#include <vector>
#include <string>

#include "defaultTower.h"
#include "portal.h"
#include "base.h"
#include "getTile.h"
#include "shoot.h"
#include "spawnMonster.h"
#include "wave.h"

class Game {
public:
	Wave waveMgr;

	std::vector <Tower*> towers;
	std::vector <Tile*> tiles;
	std::vector <Portal*> portals;
	std::vector <Base*> bases;
	std::vector <Monster*> monsters;
	std::vector <Bullet*> bullets;
	Game();
	void start();
	void addTower(int coordX, int coordY, std::string type);
	void addTile(int coordX, int coordY);
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