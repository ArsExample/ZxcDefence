﻿#include <SFML/Graphics.hpp>
#include <Windows.h>

#include "mainMenu.h"
#include "testField.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "ZXC DEFENCE");
	ShowWindow(window.getSystemHandle(), SW_MAXIMIZE); // открытие игры на полный экран, но окном

	window.setFramerateLimit(60);

	/*createMainMenu(window);*/
	createTestField(window);

	return 0;
}