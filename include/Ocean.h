#pragma once

#include "object/Predator.h"
#include "object/Prey.h"
#include "object/Coral.h"
#include "object/Stone.h"
#include "Cell.h"
#include "common.h"

struct OBJ{
    int predators;
    int prey;
};

class Ocean{

private:

    int size;
    Cell ** cells;
    vector<OBJ> numberOfCreatures;

    set<Prey *> prey;
    set<Predator *> predators;
    set<Stone *> stones;
    set<Coral *> corals;

public:

    explicit Ocean(int = 100);
    ~Ocean();

    void print(ostream &);
    void addObjects();
    void clear();
    void run();
    void eraseDied();

    void delObj (Prey *);
    void delObj (Predator *);

    Cell * getCell (int x, int y);

    void addObject(Predator *obj);
    void addObject(Prey *obj);

};