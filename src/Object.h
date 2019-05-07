#include "Cell.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType {
    STONE, CORAL, PREY, PREDATOR, ObjTypeEnd
};

class Object {

protected:
    Cell * cell;

public:
    Object (Cell * = nullptr);
    virtual void live() = 0;
    void setCell(Cell*);

};

