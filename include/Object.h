#pragma once

#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'
#define SPACE_N '_'

class Predator;
class Prey;
class Coral;
class Stone;

enum ObjType {
    STONE, CORAL, PREY, PREDATOR, ObjTypeEnd
};

struct COORDINATES{
    int x, y;
};

class Cell;

class Object {

public:

    Cell * cell;
    int liveTime = -1;
    vector<COORDINATES> steps;
    ObjType objType;
    int reproductionTime;
    int reproductionTimer;

    explicit Object (Cell * = nullptr, ObjType = ObjTypeEnd);

    void setCell(Cell *);

    void makeStep();

    virtual bool checkCell (Cell *);

    virtual void reproduction();

    virtual Object * createObject(Cell *);

};

