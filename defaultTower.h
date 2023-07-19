#pragma once
#include "tower.h"

class DefaultTower: public Tower
{
public:
	int attackRange = 1;

	DefaultTower(int coordX, int coordY, std::vector <Tile*> allTiles);
	void coordsInit(int coordX, int coordY);
	void upgrade();
	void downgrade();
	void rotate();
	void attack(std::vector <Bullet*>& bullets);
	void aim(std::vector <Monster*>& monsters);
	int checkRange();
	void fullDraw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, std::vector <Bullet*>& bullets, std::vector <Monster*>& monsters);
	void ttlSync();
	std::vector <Tile*> getNearbyTiles(std::vector <Tile*> allTiles);
};