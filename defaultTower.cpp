	#include "defaultTower.h"

DefaultTower::DefaultTower(int coordX, int coordY, std::vector <Tile*> allTiles)
{
	coordsInit(coordX, coordY);

	timer = Timer();

	nearbyTiles = getNearbyTiles(allTiles);

	level = 1;
	damage = 1;
	attackRange = 1;
}

void DefaultTower::update(sf::RenderWindow& window, std::vector <Bullet*>& bullets, std::vector <Monster*>& monsters)
{
	timer.update();

	// user click
	// ----------------------------------------------------------------------------------------
	checkTargeted(window, baseSprite);
	checkClicked();
	// ----------------------------------------------------------------------------------------


	if (!target)
	{
		aim(monsters);
	}
	else
	{
		rotate();
		checkRange();
	}

	attack(bullets);

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

void DefaultTower::rotate()
{
	sf::Vector2f v((*target)->sprite.getPosition().x + ((*target)->w) / 2, (*target)->sprite.getPosition().y + ((*target)->h) / 2);
	sf::Vector2f vd = v - gunSprite.getPosition();

	gunSprite.setRotation(std::atan2(vd.y, vd.x) * 180.f / 3.14f - 180);
}

std::vector <Tile*> DefaultTower::getNearbyTiles(std::vector <Tile*> allTiles)
{

	std::vector <Tile*> temp;
	int i;
	int j;

	int _x;
	int _y;

	for (i = -attackRange; i <= attackRange; i++) {
		for (j = -attackRange; j <= attackRange; j++) {
			_x = i;
			_y = j;

			if (getTileByCoords(relX + _x, relY + _y, allTiles) != 0)
			{
				temp.push_back(getTileByCoords(relX + _x, relY + _y, allTiles));
			}
			else
			{
			}
		}
	}


	return temp;
}

void DefaultTower::aim(std::vector <Monster*>& monsters) //debugged
{

	int i;

	//if (!target)
	//{
		for (i = 0; i < nearbyTiles.size(); i++)
		{
			if (getMonsterByTile(nearbyTiles[i], monsters) != 0)
			{
				target = getMonsterByTile(nearbyTiles[i], monsters);
				std::cout << "targeted" << std::endl;
			}
		}
	//}
	//else {
	//	std::cout << "already targeted" << std::endl;
	//}
	

}

int DefaultTower::checkRange()
{
	int i;

	for (i = 0; i < nearbyTiles.size(); i++)
	{
		if (getTileByMonster(*target, nearbyTiles) == 0 || (*target)->health <= 0)
		{
			target = NULL;
			timer.stop();
			return 0;
		}
	}
}

void DefaultTower::attack(std::vector <Bullet*>& bullets)
{
	if (timer.stopped)
	{
		if (target)
		{
			std::cout << "timer attacking" << std::endl;

			addBullet(relX, relY, *target, bullets);
			timer.setTimerSec(2);
			timer.start();
		}
	}
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
	baseSprite.setPosition(x + w/2, y + h/2);
	baseSprite.setOrigin(w / 2, h / 2);

	gunImage.loadFromFile("textures/defaultTowerGun1.png");
	gunTexture.loadFromImage(gunImage);
	gunSprite.setTexture(gunTexture);
	gunSprite.setPosition(x + 60, y + 60);
	gunSprite.setOrigin(60, 30);
}