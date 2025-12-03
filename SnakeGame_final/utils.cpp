#include "Utils.h"
using namespace sf;
using namespace std;

void utils::DrawSnake(RenderWindow& window, const Snake& snake)//piesia snake lange
{
    RectangleShape segment(sf::Vector2f(static_cast<float>(CELL_SIZE - 1), static_cast<float>(CELL_SIZE - 1)));
    //sukuria staciakampi segmentui
    for (size_t i = 0; i < snake.body.size(); ++i)//eina per visus snake segmentus
    {
        if (i == 0)
            segment.setFillColor(Color(255, 105, 180));//pink galva
        else
            segment.setFillColor(Color(255, 182, 193));//pink kunas

        segment.setPosition(//nustato segmento pozicija
            static_cast<float>(snake.body[i].x * CELL_SIZE),
            static_cast<float>(snake.body[i].y * CELL_SIZE)
        );
        window.draw(segment);//piesia segmenta lange
    }
}

void utils::DrawFood(RenderWindow& window, const Food& food)//piesia food lange
{//sukuria staciakampi maistui
    RectangleShape foodShape(Vector2f(static_cast<float>(CELL_SIZE - 1), static_cast<float>(CELL_SIZE - 1)));
    foodShape.setFillColor(Color::Magenta);
    foodShape.setPosition(//nustato maisto pozicija
        static_cast<float>(food.position.x * CELL_SIZE),
        static_cast<float>(food.position.y * CELL_SIZE)
    );
    window.draw(foodShape);//piesia maista lange
}

void utils::DrawUI(RenderWindow& window, const Snake& snake, const Font& font)//piesia vartotoja sasaja
{
    Text scoreText;//sukuria teksta taskams
    scoreText.setFont(font);//sriftas
    scoreText.setString("Score: " + to_string(snake.score));
    scoreText.setCharacterSize(24);//srifto dydis
    scoreText.setFillColor(Color::Magenta);
    scoreText.setPosition(10.f, 10.f);//pozicija virsutiniame kairiajame kampe
    window.draw(scoreText);//piesia teksta lange
}

void utils::DrawGameOver(RenderWindow& window, const Font& font)//piesia game over ekrana
{
   Text gameOverText;//sukuria teksta
    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER!\nPress R to restart");
    gameOverText.setCharacterSize(32);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setStyle(Text::Bold);

    FloatRect textRect = gameOverText.getLocalBounds();//gauna teksto ribas
    gameOverText.setOrigin(textRect.left + textRect.width / 2.0f,//centruoja x asyje
        textRect.top + textRect.height / 2.0f),//centruoja y asyje
    gameOverText.setPosition(static_cast<float>(WINDOW_WIDTH) / 2.0f,//pozicija ekrano centre x
        static_cast<float>(WINDOW_HEIGHT) / 2.0f);//pozicija ekrano centre y

    window.draw(gameOverText);//piesia teksta lange
}