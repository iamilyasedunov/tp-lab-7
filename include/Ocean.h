#ifndef _OCEAN_H_
#define _OCEAN_H_
#include "Common.h"
#include "Object.h"
#include <list>
class Object;
class Cell;
class Ocean
{
friend Cell;
friend Object;
private:
	Cell** cells;//двумерный массив указателей
	list<Object*> stuff;
	int size_pred = 0;
	int size_prey = 0;
public:
	Ocean();
	~Ocean();
	void print();
	void addObjects(int numStone,int numPrey,int numPred);
	void run();
	void eat();
	void Kill();
	void reproduction();
};
#endif