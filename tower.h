#pragma once
#include "button.h"
#include "shoot.h"
#include "timer.h"

class Tower: public Button
{
public:
	int x, y, w, h, level, damage, range, relX, relY, targetID;
	sf::Vector2f v, vd;
	bool attacked = false;
	std::vector <Tile*> nearbyTiles;
	Monster** target;
	Timer timer;

	sf::Image baseImage;
	sf::Texture baseTexture;
	sf::Sprite baseSprite;
	sf::Image gunImage;
	sf::Texture gunTexture;
	sf::Sprite gunSprite;

	Tower();
	Tower(int coordX, int coordY, std::vector <Tile*> allTiles);
	void coordsInit(int coordX, int coordY);
	virtual void attack(std::vector <Bullet*>& bullets) = 0;
	virtual void aim(std::vector <Monster*>& monsters) = 0;
	virtual void updateTarget(std::vector <Monster*>& monsters) = 0;
	virtual int checkRange() = 0;
	virtual void upgrade() = 0;
	virtual void downgrade() = 0;
	virtual void rotate() = 0;
	virtual void fullDraw(sf::RenderWindow& window) = 0;
	virtual void update(sf::RenderWindow& window, std::vector <Bullet*>& bullets, std::vector <Monster*>& monsters) = 0;
	virtual std::vector <Tile*> getNearbyTiles(std::vector <Tile*> allTiles) = 0;
};