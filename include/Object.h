//
// CreatToed by Илья on 06.06.2019.
//

#ifndef LAB7_OBJECT_H
#define LAB7_OBJECT_H

#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType {STONE,CORAL,PREY,PREDATOR};

class Ocean;
class Cell;
class Object
{
protected:
    Cell *cell;
    size_t lifetime;
    ObjType  type;
    size_t reproduce_time;
public:
    Object(Cell* c = nullptr);
    virtual ~Object() = default;
    virtual bool live() = 0; // жизнь объекта
    virtual char getSymbol() = 0;
    virtual void move() {};
    virtual void reproduce() {};
    Cell* getCell();
    ObjType getType();
    void setLifetime(size_t lt);
};
#endif //LAB7_OBJECT_H
