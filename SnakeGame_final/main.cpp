#include <SFML/Graphics.hpp>
#include <ctime>

#include "Game.h"
#include "Utils.h"

using namespace sf;


int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    sf::RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        return -1;
    }

    Game game;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::R))
        {
            game.Reset();
        }

        game.HandleInput();
        game.Update();

        window.clear(Color::White);

        utils::DrawSnake(window, game.snake);
        utils::DrawFood(window, game.food);
        utils::DrawUI(window, game.snake, font);

        if (!game.snake.alive)
        {
            utils::DrawGameOver(window, font);
        }

        window.display();
    }

    return 0;
}