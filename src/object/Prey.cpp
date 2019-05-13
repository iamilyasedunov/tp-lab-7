
#include <object/Prey.h>

#include "../include/object/Prey.h"

Prey::Prey(Cell * cell) : Object(cell, PREY) {

    liveTime = rand() % 100;
    reproductionTime = rand() % 10;
    reproductionTimer = reproductionTime;
    steps.push_back(cell->cord);

}

bool Prey::checkCell (Cell * cell){
    return cell != nullptr && !(cell->getObjType() == STONE || cell->getObjType() == CORAL
                                || cell->getObjType() == PREY || cell->getObject() == nullptr);
}

Prey::~Prey() {

   this->cell->getOcean()->delObj(this);

}

Prey *Prey::createObject(Cell * cell) {

    auto obj = new Prey(cell);
    cell->setObject(obj);
    cell->getOcean()->addObject(obj);

    return obj;

}
