#pragma once

#include "Objects.h"

class Game//zaidimo klasse
{
public:
    Snake snake;//gyvates objektas
    Food food;//maisto objektas
    float timer;//atnaujinimo laikmatis
    float timeStep;//laiko zingsnis

    Game();//konstruktorius
    void Update();//busenos atnaujinimas
    void Reset();//zaidimo atstatymas
    void HandleInput();//ivisties apdorojimas
};