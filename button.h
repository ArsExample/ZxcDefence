#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>

class Button
{
public:
	int x, y, w, h, mouseX, mouseY;
	int targeted;
	int clicked;
	int twoImg;
	Button();
	Button(int buttonX, int buttonY, std::string filename);
	Button(int buttonX, int buttonY, std::string filename, std::string filename2);
	void checkTargeted(sf::RenderWindow& window, sf::Sprite sprite);
	void checkClicked();
	int isTargeted();
	sf::Vector2i pixelPos;
	sf::Vector2f pos;
	int isClicked();
	void update(sf::RenderWindow& window);
private:
	sf::Image image;
	sf::Texture texture;
	sf::Image image2;
	sf::Texture texture2;
	sf::Sprite baseSprite;
	sf::Clock clock;
	sf::Time elapsedAfterClick1;
	void fullDraw(sf::RenderWindow& window);
};