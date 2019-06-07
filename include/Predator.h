//
// CreatToed by Илья on 06.06.2019.
//

#ifndef LAB7_PREDATOR_H
#define LAB7_PREDATOR_H

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"

class Predator : public Object
{
private:
    bool fed = false;
public:
    Predator(Cell* cell);
    bool live() override;
    char getSymbol() override;
    void move() override;
    void reproduce() override;
    bool eatTo();

};
#endif //LAB7_PREDATOR_H
