#pragma once
#include "bullet.h"

class DefaultBullet : public Bullet {
public:
	DefaultBullet(int coordX, int coordY, Monster* _target);
	void coordsInit(int coordX, int coordY);

	void update(sf::RenderWindow& window, float time);
	void fullDraw(sf::RenderWindow& window);
	void move(float time);
	void die();
};