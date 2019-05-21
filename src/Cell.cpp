#include "Common.h"
#include "Ocean.h"
#include "Cell.h"
class Object;
class Ocean;
void Cell::init(Pair p, Ocean* oc)
{
	crd = p;
	ocean = oc;
	obj = nullptr;
}
Object* Cell::getObject()
{
	return obj;
}
void Cell::setObject(Object* _obj)
{
	obj = _obj;
}
void Cell::killMe()
{
	obj = nullptr;
}