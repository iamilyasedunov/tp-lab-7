#pragma once

#include "../include/Ocean.h"

Ocean::Ocean(int size){

    this->size = size;

    numberOfCreatures.push_back({0, 0});

    addObjects();

}

void Ocean::addObjects() {

    srand(time(nullptr));

    cells = new Cell * [size];

    OBJ count = {0, 0};

    for (int i = 0; i < size; i++){

        cells[i] = new Cell[size];

        for (int j = 0; j < size; j++){

            cells[i][j] =  *(new Cell (COORDINATES{i, j}, this));


            switch (ObjType(rand() % (ObjTypeEnd + 1))){

                case STONE: {

                    auto obj = new Stone(&cells[i][j]);
                    stones.insert(obj);
                    cells[i][j].setObject(obj);

                    break;

                }

                case PREDATOR: {

                    auto obj = new Predator(&cells[i][j]);
                    predators.insert(obj);
                    cells[i][j].setObject(obj);
                    count.predators++;

                    break;

                }

                case PREY: {

                    auto obj = new Prey(&cells[i][j]);
                    prey.insert(obj);
                    cells[i][j].setObject(obj);
                    count.prey++;

                    break;

                }

                case CORAL: {

                    auto obj = new Coral(&cells[i][j]);
                    corals.insert(obj);
                    cells[i][j].setObject(obj);

                    break;

                }

                default: {

                    cells[i][j].setObject(nullptr);
                    break;

                }

            }

        }

    }

    numberOfCreatures.push_back(count);

}

void Ocean::clear(){

    for (int i = 0; i < size; i++)
        delete [] cells[i];

    cells = nullptr;

}

Ocean::~Ocean(){

    clear();

}

void Ocean::print(ostream &out){

    out << "\nThe number of predators: " << predators.size() << "\n";
    out << "The number of prey: " << prey.size() << "\n";


    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if (cells[i][j].getObject() == nullptr) {
                out << SPACE_N;
                continue;
            }

            switch (cells[i][j].getObjType()) {

                case STONE:
                    out << STONE_N;
                    break;

                case CORAL:
                    out << CORAL_N;
                    break;

                case PREY:
                    out << PREY_N;
                    break;

                case PREDATOR:
                    out << PREDATOR_N;
                    break;

                default:
                    break;

            }

        }

        out << endl;

    }

}

Cell * Ocean::getCell (int x, int y){

    if (x < size && y < size && x >= 0 && y >= 0)
        return &cells[x][y];

    return nullptr;

}

void Ocean::delObj(Prey * obj){
    prey.erase(obj);
}

void Ocean::delObj(Predator * obj){
    predators.erase(obj);
}

void Ocean::eraseDied() {

    for (auto p : prey)
        if (p->cell == nullptr || p->cell->getObject() != p)
            prey.erase(p);

    for (auto p : predators)
        if (p->cell == nullptr || p->cell->getObject() != p)
            predators.erase(p);

}

void Ocean::run(){

    eraseDied();

    for (auto p : predators)
        p->makeStep();

    eraseDied();

    for (auto p : prey)
        p->makeStep();

    eraseDied();

    numberOfCreatures.push_back({(int)predators.size(), (int)prey.size()});

}

void Ocean::addObject(Predator *obj) {
    predators.insert(obj);
}

void Ocean::addObject(Prey * obj){
    prey.insert(obj);
}
