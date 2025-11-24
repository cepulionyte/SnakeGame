#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
using namespace std;
using namespace sf;


Game::Game()
{
    Reset();
}

void Game::Update()
{
    if (!snake.alive) return;

    timer += timeStep;

    if (timer >= 1.0f / snake.speed)
    {
        snake.Move();

        if (snake.GetHead() == food.position)
        {
            snake.Grow();
            food.Respawn(snake.body);
        }

        timer = 0;
    }
}

void Game::Reset()
{
    snake.Reset();
    food.Respawn(snake.body);
    timer = 0;
    timeStep = 1.0f / 60.0f;
}

void Game::HandleInput()
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