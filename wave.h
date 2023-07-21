#pragma once
#define NOMINMAX

#include <iostream>
#include <Windows.h>

#include <thread>
#include "simpleFunctions.h"
#include "timer.h"
#include "spawnMonster.h"

class Wave {
	struct MonsterToSpawnStruct
	{
		int x = 0;
		int y = 0;
		int pX = 0;
		int pY = 0;
		int bX = 0;
		int bY = 0;
		std::string type = "";
		int ID = 0;
	};

public:
	int pX, pY, bX, bY;
	int waveNumber;
	int monsterSpawning;
	int prevMonsterID = 0;
	bool spawnedWave;
	std::vector <std::string> types;
	std::string temp;
	std::vector <MonsterToSpawnStruct> toSpawnQueue;

	Wave();
	Wave(int _pX, int _pY, int _bX, int _bY);
	int addWave(std::string monsters, int waveNumber);
	void update(std::vector <Monster*>& _monsterArray);
private:
	Timer timer;
};