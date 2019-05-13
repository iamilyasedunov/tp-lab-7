#include "../include/object/Predator.h"

Predator::Predator(Cell * cell) : Object(cell, PREDATOR) {

    liveTime = rand() % 100;
    reproductionTime = rand() % 10;
    steps.push_back(cell->cord);
    reproductionTimer = reproductionTime;

}

bool Predator::checkCell (Cell * cell){

    return cell != nullptr && !(cell->getObjType() == STONE || cell->getObjType() == CORAL
                            || cell->getObjType() == PREDATOR);

}

Predator::~Predator() {

    this->cell->getOcean()->delObj(this);

}

Predator *Predator::createObject(Cell * cell) {

    auto obj = new Predator(cell);
    cell->setObject(obj);
    cell->getOcean()->addObject(obj);

    return obj;

}