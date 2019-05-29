#include "Predator.h"


Predator::Predator(Cell* cell_, Ocean* ocean_):Prey(cell_, ocean_)
{
    life = 40;
    type = PREDATOR;
    ocean = ocean_;
    vision = new WildViewField(cell, 6, ocean, this);
    speed = 2;
}

Predator::~Predator()
{
    //dtor
}

void Predator::Eat(int num)
{
    life += num;
}
