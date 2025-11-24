#include "Utils.h"
using namespace sf;
using namespace std;

void utils::DrawSnake(RenderWindow& window, const Snake& snake)
{
    RectangleShape segment(sf::Vector2f(static_cast<float>(CELL_SIZE - 1), static_cast<float>(CELL_SIZE - 1)));

    for (size_t i = 0; i < snake.body.size(); ++i)
    {
        if (i == 0)
            segment.setFillColor(Color(255, 105, 180));
        else
            segment.setFillColor(Color(255, 182, 193));

        segment.setPosition(
            static_cast<float>(snake.body[i].x * CELL_SIZE),
            static_cast<float>(snake.body[i].y * CELL_SIZE)
        );
        window.draw(segment);
    }
}

void utils::DrawFood(RenderWindow& window, const Food& food)
{
    RectangleShape foodShape(Vector2f(static_cast<float>(CELL_SIZE - 1), static_cast<float>(CELL_SIZE - 1)));
    foodShape.setFillColor(Color::Magenta);
    foodShape.setPosition(
        static_cast<float>(food.position.x * CELL_SIZE),
        static_cast<float>(food.position.y * CELL_SIZE)
    );
    window.draw(foodShape);
}

void utils::DrawUI(RenderWindow& window, const Snake& snake, const Font& font)
{
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + to_string(snake.score));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(Color::Magenta);
    scoreText.setPosition(10.f, 10.f);
    window.draw(scoreText);
}

void utils::DrawGameOver(RenderWindow& window, const Font& font)
{
   Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER!\nPress R to restart");
    gameOverText.setCharacterSize(32);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setStyle(Text::Bold);

    FloatRect textRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    gameOverText.setPosition(static_cast<float>(WINDOW_WIDTH) / 2.0f,
        static_cast<float>(WINDOW_HEIGHT) / 2.0f);

    window.draw(gameOverText);
}