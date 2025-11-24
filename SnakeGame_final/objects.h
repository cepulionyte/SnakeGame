#pragma once

#include "Defines.h"
#include <vector>

using namespace std;
using namespace sf;

enum class Direction { UP, DOWN, LEFT, RIGHT };

struct Position
{
    int x, y;
    Position(int x = 0, int y = 0);
    bool operator==(const Position& other) const;
};

class Snake
{
public:
    vector<Position> body;
    Direction direction;
    float speed;
    int score;
    bool alive;

    Snake();
    void Reset();
    void Move();
    void Grow();
    void ChangeDirection(Direction newDir);
    const Position& GetHead() const;
};

class Food
{
public:
    Position position;

    Food();
    void Respawn(const vector<Position>& snakeBody);

private:
    bool IsInSnake(const vector<Position>& snakeBody, const Position& pos);
};