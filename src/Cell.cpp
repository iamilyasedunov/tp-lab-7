//
// CreatToed by Илья on 06.06.2019.
//

#include "Cell.h"

void Cell::init(Pair p, Ocean *oc)
{
    ocean = oc;
    crd = p;
}

Object* Cell::getObject()
{
    return object;
}

Ocean* Cell::getOcean()
{
    return ocean;
}


void Cell::setObject(Object* obj)
{
    object = obj;
}

void Cell::killMe()
{
    if (object)
    {
        delete object;
        object = nullptr;
    }
}

Cell* Cell::getFreeCellAround()
{
    return ocean->findEmpty(crd);
}

Cell* Cell::getPreyAround()
{
    return ocean->findPrey(crd);
}

