#pragma once
#include "defaultBullet.h"
#include "defaultMonster.h"

void addBullet(int coordX, int coordY, Monster* target, std::vector <Bullet*>& bullets);
Monster** getMonsterByTile(Tile* tile, std::vector <Monster*>& monsters);
Monster** getMonsterByID(int ID, std::vector <Monster*>& monsters);
Tile* getTileByMonster(Monster* monster, std::vector <Tile*> tiles);