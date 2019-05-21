#ifndef _CELL_H_
#define _CELL_H_
#include "Common.h"
#include "Ocean.h"
class Object;
class Ocean;
class Cell
{
friend Ocean;
friend Object;
private:
	Pair crd;
	Object *obj=nullptr;
	Ocean *ocean;
public:
	Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr)
	{
		crd = p;
		ocean = oc;
	}
	void init(Pair p, Ocean* oc);
	Object* getObject();
	void setObject(Object* _obj);
	void killMe();
};
#endif