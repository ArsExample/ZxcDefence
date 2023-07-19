#include "bullet.h"

Bullet::Bullet() {
	coordsInit(0, 0);
}

Bullet::Bullet(int coordX, int coordY) {
	coordsInit(coordX, coordY);
}

void Bullet::coordsInit(int coordX, int coordY) {
	relX = coordX;
	relY = coordY;

	x = ((coordX - 1) * 120) + 35;
	y = ((coordY - 1) * 120) + 35;

	image.loadFromFile("textures/defaultBullet1.png");
	w = image.getSize().x;
	h = image.getSize().y;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}