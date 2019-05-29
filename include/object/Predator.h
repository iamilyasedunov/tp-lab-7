#pragma once

#include "../Live.h"
#include "../Ocean.h"

class Predator : public Live {

public:

    explicit Predator (Cell *);
    ~Predator ();

    bool checkCell (Cell *) override;

    Predator * createObject(Cell *) override;

};

