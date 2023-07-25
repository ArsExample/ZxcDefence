#pragma once
#include "monster.h"

class DefaultMonster: public Monster {
public:
	DefaultMonster(int coordX, int coordY, int pX, int pY, int bX, int bY, int ID);
	void coordsInit(int coordX, int coordY, int pX, int pY, int bX, int bY);
	void move(std::vector <Tile*> tiles, float time, int& moneyBalance);
	void die(int& moneyBalance);
	void fullDraw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, float time, std::vector <Tile*> tiles, int& moneyBalance);
};