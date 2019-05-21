#include "Common.h"
#include "Object.h"
#include "Cell.h"
Object::Object(Cell* _cell)
{
	cell = _cell;
	lifeChance = chance;
};
//Object::~Object()
//{
//}
Object* Object::getObject()
{
	return this;
}
char Object::getSymbol()
{
	return symbol;
}
void Object::live()
{
	mylife++;
}
void Object::setCell(Cell* _cell)
{
	cell = _cell;

}

