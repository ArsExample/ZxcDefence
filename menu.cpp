#include "menu.h"

Menu::Menu()
{
	timer = Timer();

	//coordsInit(0, 0);
	opened = false;
}

Menu::Menu(int coordX, int coordY, std::string _type)
{
	timer = Timer();

	coordsInit(coordX, coordY);
	opened = false;
	menuType = _type;

	createElements();
}

void Menu::update(sf::RenderWindow& window)
{
	checkTargeted(window);
	checkClicked();

	if (opened)
	{
		window.draw(menuSprite);
		updateElements(window);
	}

	timer.update();
}

void Menu::checkTargeted(sf::RenderWindow& window)
{
	// std::cout << "mx: " << mouseX << " my: " << mouseY << " spriteX: " << baseSprite.getGlobalBounds().left << " spriteX + w: " << baseSprite.getGlobalBounds().left + baseSprite.getGlobalBounds().width << std::endl;

	pixelPos = sf::Mouse::getPosition(window);
	pos = window.mapPixelToCoords(pixelPos);

	mouseX = pos.x;
	mouseY = pos.y;

	if (menuSprite.getGlobalBounds().contains(mouseX, mouseY))
	{
		targeted = true;
	}
	else {
		targeted = false;
	}
}

void Menu::checkClicked()
{
	if (opened)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !targeted)
		{
			if (timer.stopped)
			{
				close();
			}
		}
	}
}


void Menu::open()
{
	opened = true;
	timer.setTimerMilisec(300);
	timer.start();
}

void Menu::close()
{
	opened = false;
}

void Menu::createElements()
{
	if (strcmp(menuType.c_str(), "new_tower") == 0)
	{
		menuElements.push_back(MenuElement());
		menuElements[0].button = new Button(x, y, "textures/defaultTowerMenuImage1.png");
		menuElements[0].description = "10 monet";
	}
}

void Menu::updateElements(sf::RenderWindow& window)
{
	for (int i = 0; i < menuElements.size(); i++)
	{
		//TODO: fix this memory problem

		sf::Font font;
		sf::Text desc;

		font.loadFromFile("Kristen ITC.ttf");
		desc = sf::Text("", font, 20);
		desc.setPosition(x + 130, y + 45);
		desc.setString(menuElements[i].description);

		window.draw(desc);
		menuElements[i].button->update(window);
		if (menuElements[i].button->isClicked())
		{

			//button.type
			towerToSpawn = "default";
		}
	}
}

void Menu::coordsInit(int coordX, int coordY)
{
	relX = coordX;
	relY = coordY;

	x = (coordX) * 120;
	y = (coordY - 1) * 120;

	menuImage.loadFromFile("textures/smallMenuLayout.png");
	//std::cout << image.loadFromFile("textures/tileForTower.png") << std::endl;
	w = menuImage.getSize().x;
	h = menuImage.getSize().y;
	menuTexture.loadFromImage(menuImage);
	menuSprite.setTexture(menuTexture);
	menuSprite.setPosition(x, y);
}