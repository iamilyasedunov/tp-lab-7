#pragma once

#include <Object.h>
#include "Ocean.h"

class Prey : public Object {

public:

    explicit Prey (Cell * );
    ~Prey();

    bool checkCell (Cell * cell) override;

    Prey * createObject(Cell *) override;

};

