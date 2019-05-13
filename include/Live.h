#pragma once

#include "Object.h"

class Live : public Object {

public:

    int reproductionTime{};
    int reproductionTimer{};
    int liveTime = -1;
    vector<COORDINATES> steps;

    Live (Cell * cell, ObjType objType) : Object (cell, objType){}

    void makeStep();

    virtual bool checkCell (Cell *);

    virtual void reproduction();


};

