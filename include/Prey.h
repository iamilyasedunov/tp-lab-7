//
// CreatToed by Илья on 06.06.2019.
//

#ifndef LAB7_PREY_H
#define LAB7_PREY_H


#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"

class Cell;
class Ocean;
class Prey : public Object
{
public:
    Prey(Cell* cell);
    bool live() override;
    char getSymbol() override;
    void move() override;
    void reproduce() override;
};


#endif //LAB7_PREY_H
