#pragma once

#include "../Cell.h"

class Stone : public Object{

public:

    explicit Stone (Cell * cell):Object(cell, STONE){}

};
