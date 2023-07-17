#pragma once
#include "button.h"

class Tower: public Button
{
public:
	int level, damage, relX, relY;

	sf::Image baseImage;
	sf::Texture baseTexture;
	sf::Sprite baseSprite;
	sf::Image gunImage;
	sf::Texture gunTexture;
	sf::Sprite gunSprite;

	Tower();
	Tower(int coordX, int coordY);
	void coordsInit(int coordX, int coordY);
	virtual void attack() = 0;
	virtual void upgrade() = 0;
	virtual void downgrade() = 0;
	virtual void fullDraw(sf::RenderWindow& window) = 0;
	virtual void update(sf::RenderWindow& window) = 0;
};