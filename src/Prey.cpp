//
// CreatToed by Илья on 06.06.2019.
//

#include "Prey.h"
#include "Cell.h"
#include "Object.h"

Prey::Prey(Cell *cell): Object(cell)
{
    lifetime = LIMITPREY;
    type = ObjType::PREY;
    reproduce_time = REPRODUCETIME;
}

bool Prey::live()
{
    if (!lifetime--)
        return false;
    move();
    if (reproduce_time == 0)
    {
        reproduce();
        reproduce_time = REPRODUCETIME;
    }
    reproduce_time--;
    return true;
}

char Prey::getSymbol()
{
    return PREY_N;
}

void Prey::move()
{
    Cell* newCell = cell->getFreeCellAround();
    if (newCell)
    {
        cell->setObject(nullptr);
        cell = newCell;
        newCell->setObject(this);
    }
}

void Prey::reproduce()
{
    Cell* newCell = cell->getFreeCellAround();
    if (newCell)
    {
        auto* child = new Prey(newCell);
        newCell->setObject(child);
        newCell->getOcean()->addStuff(child);
    }
}