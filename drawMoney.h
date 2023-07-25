#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class DrawMoney {
public:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Font font;
	sf::Text money;

	int w, h;
	
	DrawMoney();
	DrawMoney(int x, int y);
	void update(sf::RenderWindow& window, int& moneyBalance);
};