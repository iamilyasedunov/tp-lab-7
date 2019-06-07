//
// CreatToed by Илья on 06.06.2019.
//

#ifndef LAB7_CELL_H
#define LAB7_CELL_H

#include "common.h"
#include "Object.h"
#include "Ocean.h"

class Cell
{
    friend Ocean;
private:
    Pair crd;
    Object *object;
    Ocean *ocean;
public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
            crd(p),
            object(nullptr),
            ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* getObject();
    Ocean* getOcean();
    void setObject(Object*);
    void killMe();
    Cell* getFreeCellAround();
    Cell* getPreyAround();

};
#endif
