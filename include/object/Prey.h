#pragma once

#include "../Live.h"
#include "../Ocean.h"

class Prey : public Live {

public:

    explicit Prey (Cell * );
    ~Prey();

    bool checkCell (Cell * cell) override;

    Prey * createObject(Cell *) override;

};

