#pragma once

#include "../include/Live.h"
#include "../include/Ocean.h"

bool Live::checkCell (Cell * cell){
    return false;
}

void Live::makeStep() {

    if (cell->getObjType() == CORAL || cell->getObjType() == STONE)
        return;

    liveTime--;

    if (liveTime <= 0){
        cell->setObject(nullptr);
        return;
    }

    if(--reproductionTimer == 0)
        reproduction();

    int x = rand() % 3 - 1, y = rand() % 3 - 1;

    Cell * newCell = cell->getOcean()->getCell(x + cell->cord.x, y + cell->cord.y);

    if (!checkCell(newCell)) {

        for (int i = -1; i <= 1; i++) {

            for (int j = -1; j <= 1; j++) {

                newCell = cell->getOcean()->getCell(i + cell->cord.x, j + cell->cord.y);

                if (checkCell(newCell))
                    break;

            }

            if (checkCell(newCell))
                break;

        }

    }

    if (checkCell(newCell)) {

        if (newCell->getObject() != nullptr
            && objType == PREY && newCell->getObject()->objType == PREDATOR){

            cell->setObject(nullptr);
            setCell(nullptr);

            return;

        }else if (newCell->getObject() != nullptr
                  && objType == PREDATOR && newCell->getObject()->objType == PREY) {

            newCell->setObject(this);
            cell->setObject(nullptr);
            setCell(newCell);

        }else{

            newCell->setObject(this);
            cell->setObject(nullptr);
            setCell(newCell);

        }

        steps.push_back(newCell->cord);

    }else
        steps.push_back(cell->cord);

}


void Live::reproduction() {

    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++){

            auto cur = cell->getOcean()->getCell(cell->cord.x + i, cell->cord.y + j);
            if (cur != nullptr && cur->getObject() == nullptr){
                createObject(cur);
            }

        }

    reproductionTimer = reproductionTime;

}
