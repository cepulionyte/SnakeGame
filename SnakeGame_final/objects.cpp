#include "Objects.h"
#include <algorithm>

Position::Position(int x, int y) : x(x), y(y) {}

bool Position::operator==(const Position& other) const
{
    return x == other.x && y == other.y;
}

Snake::Snake()
{
    Reset();
}

void Snake::Reset()
{
    body.clear();
    for (int i = 0; i < INITIAL_SNAKE_LENGTH; ++i)
    {
        body.push_back(Position(GRID_WIDTH / 2 - i, GRID_HEIGHT / 2));
    }
    direction = Direction::RIGHT;
    speed = INITIAL_SPEED;
    score = 0;
    alive = true;
}

void Snake::Move()
{
    if (!alive) return;

    Position newHead = body[0];

    switch (direction)
    {
    case Direction::UP:    newHead.y--; break;
    case Direction::DOWN:  newHead.y++; break;
    case Direction::LEFT:  newHead.x--; break;
    case Direction::RIGHT: newHead.x++; break;
    }

    if (newHead.x < 0 || newHead.x >= GRID_WIDTH ||
        newHead.y < 0 || newHead.y >= GRID_HEIGHT) {
        alive = false;
        return;
    }

    for (size_t i = 0; i < body.size(); ++i) {
        if (newHead == body[i]) {
            alive = false;
            return;
        }
    }

    body.insert(body.begin(), newHead);
    body.pop_back();
}

void Snake::Grow()
{
    body.push_back(body.back());
    score += 10;
    speed += SPEED_INCREMENT;
}

void Snake::ChangeDirection(Direction newDir)
{
    if ((direction == Direction::UP && newDir == Direction::DOWN) ||
        (direction == Direction::DOWN && newDir == Direction::UP) ||
        (direction == Direction::LEFT && newDir == Direction::RIGHT) ||
        (direction == Direction::RIGHT && newDir == Direction::LEFT))
    {
        return;
    }
    direction = newDir;
}

const Position& Snake::GetHead() const
{
    return body[0];
}

Food::Food()
{
    Respawn(std::vector<Position>());
}

void Food::Respawn(const std::vector<Position>& snakeBody)
{
    do {
        position.x = rand() % GRID_WIDTH;
        position.y = rand() % GRID_HEIGHT;
    } while (IsInSnake(snakeBody, position));
}

bool Food::IsInSnake(const std::vector<Position>& snakeBody, const Position& pos)
{
    return std::find(snakeBody.begin(), snakeBody.end(), pos) != snakeBody.end();
}