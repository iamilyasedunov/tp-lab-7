#pragma once

#include <Object.h>
#include "Ocean.h"

class Predator : public Object {

public:

    explicit Predator (Cell *);
    ~Predator ();

    bool checkCell (Cell *) override;

    Predator * createObject(Cell *) override;

};

