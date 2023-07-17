	#include "defaultTower.h"

DefaultTower::DefaultTower(int coordX, int coordY)
{
	coordsInit(coordX, coordY);

	level = 1;
	damage = 1;
}

void DefaultTower::update(sf::RenderWindow& window)
{
	checkTargeted(window, baseSprite);
	checkClicked();
	fullDraw(window);
}

void DefaultTower::upgrade()
{
	level += 1;
	ttlSync();
}

void DefaultTower::downgrade()
{
	level -= 1;
	ttlSync();
}

void DefaultTower::attack()
{

}

void DefaultTower::fullDraw(sf::RenderWindow& window)
{
	window.draw(baseSprite);
	window.draw(gunSprite);
}

void DefaultTower::ttlSync()  // texture to level sync
{
	switch (level)
	{
	case 1:
		baseImage.loadFromFile("textures/defaultTowerBase1.png");
		baseTexture.loadFromImage(baseImage);
		baseSprite.setTexture(baseTexture);

		gunImage.loadFromFile("textures/defaultTowerGun1.png");
		gunTexture.loadFromImage(gunImage);
		gunSprite.setTexture(gunTexture);

		break;
	case 2:
		baseImage.loadFromFile("textures/defaultTowerBase2.png");
		baseTexture.loadFromImage(baseImage);
		baseSprite.setTexture(baseTexture);

		gunImage.loadFromFile("textures/defaultTowerGun2.png");
		gunTexture.loadFromImage(gunImage);
		gunSprite.setTexture(gunTexture);

		break;
	}
}

void DefaultTower::coordsInit(int coordX, int coordY)
{
	relX = coordX;
	relY = coordY;

	x = (coordX - 1) * 120;
	y = (coordY - 1) * 120;
	
	// delete?
	baseImage.loadFromFile("textures/defaultTowerBase1.png");
	w = baseImage.getSize().x;
	h = baseImage.getSize().y;
	baseTexture.loadFromImage(baseImage);
	baseSprite.setTexture(baseTexture);
	baseSprite.setPosition(x, y);

	gunImage.loadFromFile("textures/defaultTowerGun1.png");
	gunTexture.loadFromImage(gunImage);
	gunSprite.setTexture(gunTexture);
	gunSprite.setPosition(x, y + 30);
}