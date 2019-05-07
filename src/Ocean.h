#include "Cell.h"

struct OBJ{
    int predators;
    int prey;
};

class Ocean{

private:
    int size;
    Cell ** cells;
    vector<OBJ> numberOfCreatures;

public:

    Ocean(int);

    void print() const;
    void addObjects();
    void run();

};