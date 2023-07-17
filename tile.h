#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile {
public:
	int x, y, w, h, relX, relY;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	Tile();
	Tile(int coordX, int coordY);
	void coordsInit(int coordX, int coordY);
	void update(sf::RenderWindow& window);
	int getX();
	int getY();
};