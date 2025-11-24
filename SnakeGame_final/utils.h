#pragma once

#include "Objects.h"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace utils
{
    void DrawSnake(RenderWindow& window, const Snake& snake);
    void DrawFood(RenderWindow& window, const Food& food);
    void DrawUI(RenderWindow& window, const Snake& snake, const Font& font);
    void DrawGameOver(RenderWindow& window, const Font& font);
}