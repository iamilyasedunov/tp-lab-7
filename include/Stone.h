//
// CreatToed by Илья on 06.06.2019.
//

#ifndef LAB7_STONE_H
#define LAB7_STONE_H

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"

class Stone : public Object
{
public:
    Stone(Cell* cell);
    ~Stone() = default;
    bool live() override;
    char getSymbol() override;
};


#endif //LAB7_STONE_H
