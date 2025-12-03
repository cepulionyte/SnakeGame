#include <SFML/Graphics.hpp>
#include <ctime>

#include "Game.h"
#include "Utils.h"

using namespace sf;


int main()
{
    srand(static_cast<unsigned>(time(nullptr)));// atsitiktiniu skaiciu generatoriaus inicializacija

    sf::RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");//lango sukurimas
    window.setFramerateLimit(60);//fps apribojimas 

    sf::Font font;//srifto ikelimas
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        return -1;//isejimas klaidos atveju
    }

    Game game;//zaidimo objekto sukurimas

    while (window.isOpen())//pagr zaidimo ciklas
    {
        Event event;
        while (window.pollEvent(event))//ivykiu apdorojimas
        {
            if (event.type == Event::Closed)//jei uzdaryti langa
                window.close();//uzdaryti langa
        }

        if (Keyboard::isKeyPressed(Keyboard::R))//jei paspausti r
        {
            game.Reset();//atstatyti zaidima
        }

        game.HandleInput();//ivesties apdorojimas
        game.Update();//zaidimo atnaujinimas

        window.clear(Color::White);//ekrano valymas 

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