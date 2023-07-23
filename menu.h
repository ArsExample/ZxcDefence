#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "timer.h"
#include "button.h"
#include "addTower.h"

class Menu {
	struct MenuElement
	{
		Button* button;
		std::string description;
	};
public:
	int x, y, w, h, relX, relY, mouseX, mouseY;
	bool opened, targeted;
	std::string menuType;
	Timer timer;
	std::vector <MenuElement> menuElements;
	std::string towerToSpawn = "";

	sf::Vector2i pixelPos;
	sf::Vector2f pos;

	sf::Image menuImage;
	sf::Texture menuTexture;
	sf::Sprite menuSprite;

	Menu();
	Menu(int coordX, int coordY, std::string _type);
	void coordsInit(int coordX, int coordY);
	void update(sf::RenderWindow& window);
	void open();
	void close();
	void checkTargeted(sf::RenderWindow& window);
	void checkClicked();
	void createElements();
	void updateElements(sf::RenderWindow& window);
};