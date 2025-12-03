#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
using namespace std;
using namespace sf;


Game::Game()//zaidimo konstruktorius
{
    Reset();//inicializuoja zaidima
}

void Game::Update()//zaidimo busenos atnaujinimas
{
    if (!snake.alive) return;

    timer += timeStep;//padidina laikmati

    if (timer >= 1.0f / snake.speed)// tikrina, ar laikas gyvatei judeti
    {
        snake.Move();//perkelti gyvate

        if (snake.GetHead() == food.position)//tikrina susidurima su maistu
        {
            snake.Grow();//padidina snake
            food.Respawn(snake.body);//perkelia maista
        }

        timer = 0;//nustato laikmati i 0
    }
}

void Game::Reset()//zaidimo atstatymas i pradine busena
{
    snake.Reset();//atstato gyvate
    food.Respawn(snake.body);//padeda maista
    timer = 0;//nustato laikmati i 0
    timeStep = 1.0f / 60.0f;//nustato laiko zingsni(60 fps)
}

void Game::HandleInput()//ivesties apdorojimas is klaviaturos
{
    if (Keyboard::isKeyPressed(sf::Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
        snake.ChangeDirection(Direction::UP);
    else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
        snake.ChangeDirection(Direction::DOWN);
    else if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
        snake.ChangeDirection(Direction::LEFT);
    else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
        snake.ChangeDirection(Direction::RIGHT);
}