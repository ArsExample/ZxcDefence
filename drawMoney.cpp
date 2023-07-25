#include "drawMoney.h"

DrawMoney::DrawMoney()
{

}

DrawMoney::DrawMoney(int x, int y)
{
	image.loadFromFile("textures/moneyIcon.png");
	w = image.getSize().x;
	h = image.getSize().y;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	
	font.loadFromFile("Kristen ITC.ttf");
	money = sf::Text("", font, 30);
	money.setPosition(x + 100, y + 10);
}

void DrawMoney::update(sf::RenderWindow& window, int& moneyBalance)
{
	money.setString(std::to_string(moneyBalance));

	window.draw(money);
	window.draw(sprite);
}