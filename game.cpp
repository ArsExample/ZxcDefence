#include "game.h"

Game::Game()
{

}

void Game::startWave(std::string _wave, int waveNumber)
{
	waveMgr = Wave(portals[0]->relX, portals[0]->relY, bases[0]->relX, bases[0]->relY);

	waveMgr.addWave(_wave, waveNumber);
}

void Game::addTower(int coordX, int coordY, std::string type) // TODO string -> class Type
{
	if (std::strcmp(type.c_str(), "default") == 0)
	{
		towers.push_back(new DefaultTower(coordX, coordY, tiles));
	}
}

void Game::addTile(int coordX, int coordY)
{
	tiles.push_back(new Tile(coordX, coordY));
}

void Game::addPortal(int coordX, int coordY)
{
	portals.push_back(new Portal(coordX, coordY));
}

void Game::addBase(int coordX, int coordY)
{
	bases.push_back(new Base(coordX, coordY));
}

void Game::addMonster(int coordX, int coordY, int pX, int pY, int bX, int bY, std::string type, int ID)
{
	spawnMonster(coordX, coordY, pX, pY, bX, bY, type, ID, monsters);
}

void Game::deleteMonster(Monster* _monster)
{
	monsters.erase(std::remove(monsters.begin(), monsters.end(), _monster), monsters.end());
}

void Game::deleteBullet(Bullet* _bullet)
{
	bullets.erase(std::remove(bullets.begin(), bullets.end(), _bullet), bullets.end());
}

Tower* Game::getTowerByCoords(int x, int y)
{
	int i = 0;


	for (i; i < towers.size(); i++)
	{
		if (towers[i]->relX == x)
		{
			if (towers[i]->relY == y)
			{
				return towers[i];
			}
		}
		else
		{
			std::cout << towers[i]->relX << " " << x << std::endl;
		}
	}
	return 0;
}

Tower* Game::getClickedTower()
{
	int i;
	for (i = 0; i < towers.size(); i++)
	{
		if (towers[i]->isClicked())
		{
			return towers[i];
		}
	}
	return 0;
}

Portal* Game::getPortal(int id)
{
	return portals[id];
}

Base* Game::getBase(int id)
{
	return bases[id];
}

void Game::updateAll(sf::RenderWindow& window, float time)
{
	waveMgr.update(monsters);

	//std::cout << "array size (before towers update): " << monsters.size() << std::endl;

	int i;
	for (i = 0; i < towers.size(); i++)
	{
		towers[i]->update(window, bullets, monsters);
	}

	//std::cout << "array size (after towers update): " << monsters.size() << std::endl;

	for (i = 0; i < tiles.size(); i++)
	{
		tiles[i]->update(window);
	}

	for (i = 0; i < portals.size(); i++)
	{
		portals[i]->update(window);
	}

	for (i = 0; i < bases.size(); i++)
	{
		bases[i]->update(window);
	}

	for (i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i]->wannadie)
		{
			bullets[i]->update(window, time);
		}
		else
		{
			deleteBullet(bullets[i]);
		}
	}

	for (i = 0; i < monsters.size(); i++)
	{
		if (!monsters[i]->wannadie)
		{
			monsters[i]->update(window, time, tiles);
		}
		else {
			deleteMonster(monsters[i]);
		}
	}

	//std::cout << "array size (after monsters update): " << monsters.size() << std::endl;
}