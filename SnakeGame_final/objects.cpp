#include "Objects.h"
#include <algorithm>

Position::Position(int x, int y) : x(x), y(y) {}//pozicijos konstruktorius

bool Position::operator==(const Position& other) const//poziciju palyginimo operatorius
{
    return x == other.x && y == other.y;//lygina koordinatas
}

Snake::Snake()//gyvates konstruktorius
{
    Reset();//incializuoja gyvate
}

void Snake::Reset()//gyvates atstatymas i pradine busena
{
    body.clear();//isvalo kuna
    for (int i = 0; i < INITIAL_SNAKE_LENGTH; ++i)//sukuria gyvate ekrano centre
    {
        body.push_back(Position(GRID_WIDTH / 2 - i, GRID_HEIGHT / 2));//prideda segmenta
    }
    direction = Direction::RIGHT;//pradine kryptis
    speed = INITIAL_SPEED;//pradinis greitis
    score = 0;//tasku atstatymas
    alive = true;
}

void Snake::Move()//gyvates judejimas
{
    if (!alive) return;//jei mirusi iseiti

    Position newHead = body[0];//nukopijuoja galvos pozicija

    switch (direction)//apskaiciuja nauja galvos pozicija
    {
    case Direction::UP:    newHead.y--; break;
    case Direction::DOWN:  newHead.y++; break;
    case Direction::LEFT:  newHead.x--; break;
    case Direction::RIGHT: newHead.x++; break;
    }

    if (newHead.x < 0 || newHead.x >= GRID_WIDTH ||
        newHead.y < 0 || newHead.y >= GRID_HEIGHT) {//tikrina isejima uz ribu
        alive = false;// -gyvate
        return;
    }

    for (size_t i = 0; i < body.size(); ++i) {//tikrana susidurima su savimi
        if (newHead == body[i]) {
            alive = false;//-gyvate
            return;
        }
    }

    body.insert(body.begin(), newHead);//prideda nauja galva
    body.pop_back();//pasalina uodega
}

void Snake::Grow()//gyvates didinimas
{
    body.push_back(body.back());//prideda paskutinio segmento kopija
    score += 10;//padidina taskus
    speed += SPEED_INCREMENT;//padidina greiti
}

void Snake::ChangeDirection(Direction newDir)//judejimo krypties keitimas
{
    if ((direction == Direction::UP && newDir == Direction::DOWN) ||
        (direction == Direction::DOWN && newDir == Direction::UP) ||
        (direction == Direction::LEFT && newDir == Direction::RIGHT) ||
        (direction == Direction::RIGHT && newDir == Direction::LEFT))
        //tikrina, ar nauja kryptis nera priesinga dabartinei
    {
        return;//ignoruoja priesinga kripti
    }
    direction = newDir;//nustato nauja krypti
}

const Position& Snake::GetHead() const//galvos pozicijos gavimas
{
    return body[0];//grazina galva
}

Food::Food()//maisto konstruktorius
{
    Respawn(std::vector<Position>());//padeda maista
}

void Food::Respawn(const std::vector<Position>& snakeBody)//maisto vieta atsitiktineje pozicijoje
{
    do {
        position.x = rand() % GRID_WIDTH;//random x koordinate
        position.y = rand() % GRID_HEIGHT;//random y koordinate
    } while (IsInSnake(snakeBody, position));//kol maistas gyvates viduje
}
//tikrinimas ar pozicija yra gyvateje
bool Food::IsInSnake(const std::vector<Position>& snakeBody, const Position& pos)
{
    return std::find(snakeBody.begin(), snakeBody.end(), pos) != snakeBody.end();
    //tikrina, ar tam tikra pozicija yra gyvates kuno vektoriuje (snakeBody)
}