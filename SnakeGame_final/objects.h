#pragma once

#include "Defines.h"
#include <vector>

using namespace std;
using namespace sf;

enum class Direction { UP, DOWN, LEFT, RIGHT };//kryciu isvardijimas

struct Position//pozicijos struktura
{
    int x, y;//koordinatess
    Position(int x = 0, int y = 0);//konstruktorius
    bool operator==(const Position& other) const;//palyginimo operatorius
};

class Snake//gyvates klase
{
public:
    vector<Position> body;//kuno segmentu vectorius
    Direction direction;//dabartine kryptis
    float speed;//judejimo greitis
    int score;//taskai
    bool alive;

    Snake();//konstruktorius
    void Reset();//atstatymas i pradine busena
    void Move();//gyvate judejimas
    void Grow();//gyvates didinimas
    void ChangeDirection(Direction newDir);//krypties keitinas
    const Position& GetHead() const;//galvos pozicijos gavimas
};

class Food//maisto klase
{
public:
    Position position;//maisto pozicija

    Food();//konstruktorius
    void Respawn(const vector<Position>& snakeBody);//maisto vieta

private:
    bool IsInSnake(const vector<Position>& snakeBody, const Position& pos);//tikrinimas ar gyvateje
};