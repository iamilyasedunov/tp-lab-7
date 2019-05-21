#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Common.h"

class Cell;
class Ocean;
class Object
{
friend Ocean;
friend Cell;
protected:
	
	Cell * cell;
	int mylife=0;
	char symbol;
	string type;
	int lifeChance;
public:
	
	Object(Cell* _cell);
	char getSymbol();
	Object* getObject();
	void live(); // жизнь объекта
	void setCell(Cell* _cell);
};
class Stone :public Object
{
	friend Ocean;
	friend Cell;
protected:
	
public:
	Stone(Cell* _cell) :Object(_cell)
	{
		type = "Stone";
		symbol = '#';
	}
};
class Prey :public Object
{
	friend Ocean;
	friend Cell;
protected:
public:
	Prey(Cell* _cell) :Object(_cell)
	{
		type="Prey";
		symbol = 'f';
	}

};
class Predator :public Object
{
	friend Ocean;
	friend Cell;
protected:
	
public:
	Predator(Cell* _cell) :Object(_cell)
	{
		type = "Predator";
		symbol = 'S';
		
	}
};
#endif