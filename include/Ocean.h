//
// CreatToed by Илья on 06.06.2019.
//

#ifndef LAB7_OCEAN_H
#define LAB7_OCEAN_H

#include "common.h"
#include "Cell.h"
#include "Predator.h"
#include "Stone.h"
#include "Prey.h"
#include <list>

class Ocean
{
    friend Cell;
private:
    Cell** cells;
    std::list<Object*> stuff;
public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects(ObjType type, unsigned int amount);
    void addStuff(Object* obj);
    void eraseObject(Object* obj);
    void start();
    Cell* findEmpty(Pair crd);
    Cell* findPrey(Pair crd);
};
#endif //LAB7_OCEAN_H
