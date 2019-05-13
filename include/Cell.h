#pragma once

#include "Object.h"

class Ocean;

class Cell{

    friend Ocean;

private:
    Object *obj;
    Ocean *ocean;

public:

    COORDINATES cord;

    explicit Cell(COORDINATES cord = { 0, 0 }, Ocean* ocean = nullptr) :
                                            obj(nullptr), ocean(ocean), cord(cord) {}

    Object * getObject();

    ObjType getObjType();

    Ocean * getOcean();

    void setObject(Object *);

    void clear();

};
