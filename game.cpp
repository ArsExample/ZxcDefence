#include "game.h"

Game::Game()
{

}

void Game::addTower(int coordX, int coordY, std::string type) // TODO string -> class Type
{
	if (std::strcmp(type.c_str(), "default") == 0)
	{
		towers.push_back(new DefaultTower(coordX, coordY));
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

void Game::addMonster(int coordX, int coordY, int pX, int pY, int bX, int bY, std::string type)
{
	if (std::strcmp(type.c_str(), "default") == 0)
	{
		monsters.push_back(new DefaultMonster(coordX, coordY, pX, pY, bX, bY));
	}
}

void Game::deleteMonster(Monster* _monster)
{
	monsters.erase(std::remove(monsters.begin(), monsters.end(), _monster), monsters.end());
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
	int i;
	for (i = 0; i < towers.size(); i++)
	{
		towers[i]->update(window);
	}

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
}