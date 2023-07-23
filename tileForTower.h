#pragma once
#include "button.h"
#include "menu.h"

class TileForTower : public Button {
public:
	int relX, relY;
	Menu* menu;

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	TileForTower(int coordX, int coordY);
	void coordsInit(int coordX, int coordY);
	void update(sf::RenderWindow& window, std::vector <Tower*>& towers, std::vector <Tile*>& tiles);
};