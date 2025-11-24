#pragma once

#include "Objects.h"

class Game
{
public:
    Snake snake;
    Food food;
    float timer;
    float timeStep;

    Game();
    void Update();
    void Reset();
    void HandleInput();
};