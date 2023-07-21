#include "wave.h"

Wave::Wave()
{
	pX = 0;
	pY = 0;
	bX = 0;
	bY = 0;

	timer = Timer();
	prevMonsterID = 0;
}

Wave::Wave(int _pX, int _pY, int _bX, int _bY)
{
	pX = _pX;
	pY = _pY;
	bX = _bX;
	bY = _bY;

	timer = Timer();
	spawnedWave = false;
	monsterSpawning = 0;
	prevMonsterID = 0;
}

int Wave::addWave(std::string monsters, int waveNumber)
{
	types = split(monsters, '|');

	int j;

	for (int i = 0; i < types.size(); i++)
	{
		temp = types[i][0];
		if (strcmp(temp.c_str(), "D") == 0)
		{
			for (j = 0; j < types[i].size(); j++)
			{
				toSpawnQueue.push_back(MonsterToSpawnStruct());
				toSpawnQueue[j].x = pX;
				toSpawnQueue[j].y = pY;
				toSpawnQueue[j].pX = pX;
				toSpawnQueue[j].pY = pY;
				toSpawnQueue[j].bX = bX;
				toSpawnQueue[j].bY = bY;
				toSpawnQueue[j].type = "default";
				toSpawnQueue[j].ID = prevMonsterID + 1;

				prevMonsterID += 1;
			}
		}
	}

	return 1;
}

void Wave::update(std::vector <Monster*>& _monsterArray)
{
	if (!spawnedWave)
	{
		if (timer.stopped)
		{
			
			spawnMonster(toSpawnQueue[monsterSpawning].x, toSpawnQueue[monsterSpawning].y, toSpawnQueue[monsterSpawning].pX, toSpawnQueue[monsterSpawning].pY, toSpawnQueue[monsterSpawning].bX, toSpawnQueue[monsterSpawning].bY, toSpawnQueue[monsterSpawning].type, toSpawnQueue[monsterSpawning].ID, _monsterArray);
			//spawnMonster(pX, pY, pX, pY, bX, bY, "default", _monsterArray);
			monsterSpawning += 1;
			timer.setTimerSec(2);
			timer.start();

			if (toSpawnQueue.size() - monsterSpawning == 0)
			{
				spawnedWave = true;
				std::cout << "spawned full wave" << std::endl;
			}
		}
		timer.update();
	}
}
