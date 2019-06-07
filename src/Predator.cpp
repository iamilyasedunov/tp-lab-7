#include "Predator.h"
#include "Cell.h"
#include "Object.h"
#include "common.h"

Predator::Predator(Cell *cell): Object(cell)
{
    lifetime = LIMITPREDATOR;
    type = ObjType::PREDATOR;
    reproduce_time = REPRODUCETIME;
};
bool Predator::live()
{
    if(!lifetime--)
        return false;
    fed = eatTo();
    reproduce_time--;
    if (fed && reproduce_time == 0)
    {
        reproduce();
        reproduce_time = REPRODUCETIME;
    }
    if (reproduce_time == 0)
        reproduce_time = REPRODUCETIME;
    return true;
}

char Predator::getSymbol()
{
    return PREDATOR_N;
}

bool Predator::eatTo()
{
    Cell* aim = cell->getPreyAround();
    if (aim)
    {
        aim -> getObject()->setLifetime(0);
        return true;
    }
    return false;
}

void Predator::move()
{
    Cell* newCell = cell->getFreeCellAround();
    if (newCell)
    {
        cell->setObject(nullptr);
        cell = newCell;
        newCell->setObject(this);
    }
}

void Predator::reproduce()
{
    Cell* newCell = cell->getFreeCellAround();
    if (newCell)
    {
        auto* child = new Predator(newCell);
        newCell->setObject(child);
        newCell->getOcean()->addStuff(child);
    }
}