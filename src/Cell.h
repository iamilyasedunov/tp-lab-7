#include "Object.h"

struct COORDINATES{
    int x, y;
};

class Cell{

    friend Ocean;

private:
    COORDINATES cord;
    Object *obj;
    ObjType objType;
    Ocean *ocean;

public:

    explicit Cell(COORDINATES p = { 0, 0 }, Ocean* oc = nullptr) :
                                            cord(p), obj(nullptr), objType(ObjTypeEnd), ocean(oc) {}

    void init(COORDINATES p, Ocean* oc);

    Object* getObject() const;

    void setObject(Object*);

    void kill();

};
