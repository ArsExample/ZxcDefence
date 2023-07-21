#include "testField2.h"


int createTestField2(sf::RenderWindow& window)
{
    sf::Clock clock;

    Game game;
    game.addTile(2, 4);
    game.addTile(3, 4);
    game.addTile(4, 4);
    game.addTile(5, 4);
    game.addTile(6, 4);
    game.addTile(7, 4);
    game.addTile(8, 4);
    game.addTile(8, 5);
    game.addTile(8, 6);
    game.addTile(9, 6);
    game.addBase(10, 6);
    game.addTile(10, 6);
    game.addPortal(1, 4);

    game.addTower(5, 3, "default");

    //game.addMonster(1, 4, game.getPortal(0)->getX(), game.getPortal(0)->getY(), game.getBase(0)->getX(), game.getBase(0)->getY(), "default");

    game.start();

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /*if (t1.isClicked() == 1)
        {
            std::cout << "1" << std::endl;
        }*/

        if (game.getClickedTower() != 0)
        {
            if (game.getClickedTower()->level == 1)
            {
                game.getTowerByCoords(game.getClickedTower()->relX, game.getClickedTower()->relY)->upgrade();
            }
            else
            {
                game.getTowerByCoords(game.getClickedTower()->relX, game.getClickedTower()->relY)->downgrade();
            }
        }

        window.clear();
        drawField2(window);
        game.updateAll(window, time);
        window.display();
    }

    return 1;
}

int i2;

void drawField2(sf::RenderWindow& window)
{
    for (i2 = 0; i2 < 15; i2++)
    {
        sf::Vertex line[] =
        {
         sf::Vertex(sf::Vector2f(i2 * 120 + 120, 0)),
         sf::Vertex(sf::Vector2f(i2 * 120 + 120, 1080))
        };

        window.draw(line, 2, sf::Lines);
    }

    for (i2 = 0; i2 < 8; i2++)
    {
        sf::Vertex line[] =
        {
         sf::Vertex(sf::Vector2f(0, i2 * 120 + 120)),
         sf::Vertex(sf::Vector2f(1920, i2 * 120 + 120))
        };

        window.draw(line, 2, sf::Lines);
    }
}
