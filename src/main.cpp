#include "Common.h"
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
int main()
{
	Ocean  myocean;
	myocean.addObjects(2,30,10);
	for (int i = 0; i <500; i++)
	{	
		myocean.run();
		myocean.eat();
		myocean.Kill();
		myocean.reproduction();
		myocean.print();
		//system("pause");
		system("cls");
	}
	myocean.run();
	myocean.eat();
	myocean.Kill();
	myocean.reproduction();
	myocean.print();
	system("pause");
}