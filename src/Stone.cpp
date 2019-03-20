#include "Stone.h"

Stone::Stone(Cell* cell_, Ocean* ocean_):Object(cell_)
{
    life = 0;
    type = STONE;
    ocean = ocean_;
}

Stone::~Stone()
{
    //dtor
}

bool Stone::Update()
{
    life = 0;
}
