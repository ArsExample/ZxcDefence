#include "shoot.h"

void addBullet(int coordX, int coordY, Monster* target, std::vector <Bullet*>& bullets)
{
	bullets.push_back(new DefaultBullet(coordX, coordY, target));
}

Monster** getMonsterByTile(Tile* tile, std::vector <Monster*>& monsters)
{
	int i = 0;

	for (i = 0; i < monsters.size(); i++)
	{
		if (monsters[i] && tile)
		{
			if (monsters[i]->relX == tile->relX && monsters[i]->relY == tile->relY)
			{
				return &monsters[i];
			}
		}
		else
		{
			return 0;
		}

	}
	
	return 0;
}

Tile* getTileByMonster(Monster* monster, std::vector <Tile*> tiles)
{
	int i = 0;

	for (i = 0; i < tiles.size(); i++)
	{
		if (tiles[i]->relX == monster->relX && tiles[i]->relY == monster->relY)
		{
			return tiles[i];
		}
	}

	return 0;
}