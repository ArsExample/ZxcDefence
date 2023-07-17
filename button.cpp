#include "button.h"

Button::Button() 
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	targeted = 0;
	clicked = 0;
	mouseX = 0;
	mouseY = 0;
	twoImg = 0;
	clock.restart();
}

Button::Button(int buttonX, int buttonY, std::string filename) // класс UI кнопки
{
	x = buttonX;
	y = buttonY;
	image.loadFromFile(filename);
	w = image.getSize().x;
	h = image.getSize().y;
	texture.loadFromImage(image);
	baseSprite.setTexture(texture);
	baseSprite.setPosition(x, y);
	targeted = 0;
	clicked = 0;
	mouseX = 0;
	mouseY = 0;
	twoImg = 0;
	clock.restart();

}
Button::Button(int buttonX, int buttonY, std::string filename, std::string filename2)
{
	x = buttonX;
	y = buttonY;
	image.loadFromFile(filename);
	w = image.getSize().x;
	h = image.getSize().y;
	texture.loadFromImage(image);
	baseSprite.setTexture(texture);
	baseSprite.setPosition(x, y);


	image2.loadFromFile(filename2);
	texture2.loadFromImage(image2);
	targeted = 0;
	clicked = 0;
	mouseX = 0;
	mouseY = 0;
	twoImg = 1;
}
void Button::update(sf::RenderWindow& window)
{
	checkTargeted(window, baseSprite);

	checkClicked();

	fullDraw(window);
}

void Button::checkTargeted(sf::RenderWindow& window, sf::Sprite sprite)
{
	// std::cout << "mx: " << mouseX << " my: " << mouseY << " spriteX: " << baseSprite.getGlobalBounds().left << " spriteX + w: " << baseSprite.getGlobalBounds().left + baseSprite.getGlobalBounds().width << std::endl;

	pixelPos = sf::Mouse::getPosition(window);
	pos = window.mapPixelToCoords(pixelPos);

	mouseX = pos.x;
	mouseY = pos.y;

	if (sprite.getGlobalBounds().contains(mouseX, mouseY))
	{
		targeted = 1;
	}
	else {
		targeted = 0;
	}
}

void Button::checkClicked()
{
	if (targeted == 1)
	{
		if (twoImg)
		{
			baseSprite.setTexture(texture2);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			elapsedAfterClick1 = clock.getElapsedTime();
			if (elapsedAfterClick1.asMilliseconds() > 500)
			{
				clicked = 1;
				clock.restart();
			}
			else
			{
				clicked = 0;
			}
		}
		else {
			clicked = 0;
		}
	}
	else {
		if (twoImg)
		{
			baseSprite.setTexture(texture);
		}
	}
}

void Button::fullDraw(sf::RenderWindow& window)
{
	window.draw(baseSprite);
}

int Button::isTargeted()
{
	return targeted;
}
int Button::isClicked()
{
	return clicked;
}