#include "getTile.h"

Tile* getTileByCoords(int x, int y, std::vector <Tile*> tiles)
{
	int i = 0;

	try{
		for (i; i < tiles.size(); i++)
		{
			if (tiles[i]->relX == x)
			{
				if (tiles[i]->relY == y)
				{
					return tiles[i];
				}
			}
			else
			{
			}
		}
		return 0;
	}
	catch (const std::exception&)
	{
		std::cout << "some exception in getTile.cpp)))))))))))" << std::endl;
	}
}