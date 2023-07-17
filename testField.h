#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <thread>

#include "simpleFunctions.h"
#include "game.h"

int createTestField(sf::RenderWindow& window);
void getServerInfo(sf::TcpSocket& socket, Game& game);
void drawField(sf::RenderWindow& window);