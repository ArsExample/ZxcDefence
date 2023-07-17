#include <iostream>
#include <vector>
#include "mainMenu.h"
#include "button.h"

int createMainMenu(sf::RenderWindow& window)
{
	sf::Image backgroundImage;
	backgroundImage.loadFromFile("textures/background.png");

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromImage(backgroundImage);

	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 0);

	Button play(660, 552, "textures/play.png");
	Button settings(660, 672, "textures/settings.png");
	Button exit(660, 792, "textures/exit.png");

	/*play.sprite.setPosition(660, 552);
	settings.sprite.setPosition(660, 672);
	settings.sprite.setPosition(660, 792);*/


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (play.isClicked() == 1)
		{
			std::cout << "1" << std::endl;
		}

		window.clear();
		window.draw(backgroundSprite);
		play.update(window);
		settings.update(window);
		exit.update(window);
		window.display();
	}
	
	return 0;
}