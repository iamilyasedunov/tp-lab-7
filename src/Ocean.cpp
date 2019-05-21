#include "Common.h"
#include "Object.h"
class Cell;
class Ocean;
#include "Ocean.h"
#include "Cell.h"
Ocean::Ocean()
{
	cells = new Cell*[M];
	for (int i = 0; i<M; i++)
		cells[i] = new Cell[N];
	for (coord_t i = 0; i < M; i++)
		for (coord_t j = 0; j < N; j++)
			cells[i][j].init({ i,j }, this);

}
Ocean::~Ocean()
{
	delete[] cells;
	stuff.clear();
}
void Ocean::print()
{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
				if ((cells[i][j].obj) != nullptr)
					switch ((cells[i][j].obj)->getSymbol())
					{
					case('#'):
					{
						//SetConsoleTextAttribute(hConsole, 8);
						cout << "#";
						break;
					}
					case('f'):
					{
						//SetConsoleTextAttribute(hConsole, 10);
						cout << "f";
						break;
					}
					case('S'):
					{
						//SetConsoleTextAttribute(hConsole, 12);
						cout << "S";
						break;
					}
					}
				else cout << " ";
			
		}
		cout << "\n";
	}
}
void Ocean::addObjects(int numStone,int numPrey,int numPred)
{
	int flag = 1;
	
	for (int i = 0; i < numStone; i++)
	{
		while (flag)
		{
			srand(time(0));
			int x = rand() % M;
			int y = rand() % N;
			if (((cells[x][y]).obj) == nullptr)
			{
				Stone* a = new Stone(&cells[x][y]);
				cells[x][y].setObject(a);
				stuff.push_back(a);
				size_pred++;
				flag = 0;
				cout << x << ' ' << y << endl;
			}
		}
		flag = 1;

	} 

	for (int i = 0; i < numPrey; i++)
	{
		while (flag)
		{
			srand(time(0));
			int x = rand() % M;
			int y = rand() % N;
			if (((cells[x][y]).obj) == nullptr)
			{
				Prey* a = new Prey(&cells[x][y]);
				cells[x][y].setObject(a);
				stuff.push_back(a);
				size_prey++;
				flag = 0;
				cout << x << ' ' << y << endl;
			}
		}
		flag = 1;

	}

	for (int i = 0; i < numPred; i++)
	{
		while (flag)
		{
			srand(time(0));
			int x = rand() % M;
			int y = rand() % N;
			if (((cells[x][y]).obj) == nullptr)
			{
				Predator* a = new Predator(&cells[x][y]);
				cells[x][y].setObject(a);
				stuff.push_back(a);
				flag = 0;
				cout << x << ' ' << y << endl;
			}
		}
		flag = 1;

	}
	
		
//r (int i = 0; i<size_pred*k_pred; i++)
}
void Ocean::run()
{
	for (Object* obj : stuff)
	{
		if ((obj->type) != "Stone")
		{
			Pair location = ((obj->getObject())->cell)->crd;
			int x2 = -1 + rand() % 3;
			int y2 = -1 + rand() % 3;
			obj->live();
			if(((location.x + x2)<M)&&((location.y + y2)<N)&&((location.x + x2)>=0)&& ((location.x + x2) >= 0)&&(cells[location.x + x2][location.y + y2].obj==nullptr))
			{
				obj->cell->killMe();
				obj->setCell(&cells[location.x + x2][location.y + y2]);
				cells[location.x + x2][location.y + y2].setObject(obj);
				
			}
			
		}
	}
}
void Ocean::eat()
{
	int flag;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			flag = 0;
			if (((cells[i][j].obj) != nullptr) && ((cells[i][j].obj->type) == "Predator"))
			{
				if (((i + 1) <M) && (cells[i + 1][j].obj != nullptr) && (cells[i + 1][j].obj->type == "Prey"))
				{
					cells[i + 1][j].obj->mylife = exp_life;
					flag = 1;
				}
				if (((i- 1)>=0) && (cells[i-1][j].obj != nullptr) && (cells[i -1][j].obj->type == "Prey"))
				{
					cells[i - 1][j].obj->mylife = exp_life;
					flag = 1;
				}
				if (((j + 1) <N) && (cells[i][j+1].obj != nullptr) && (cells[i][j+1].obj->type == "Prey"))
				{
					cells[i][j+1].obj->mylife = exp_life;
					flag = 1;
				}
				if (((j-1) >= 0) && (cells[i][j-1].obj != nullptr) && (cells[i][j-1].obj->type == "Prey"))
				{
					cells[i][j-1].obj->mylife = exp_life;
					flag = 1;
				}
				if (((j - 1) >= 0) && ((i - 1) >= 0) && (cells[i-1][j - 1].obj != nullptr) && (cells[i-1][j - 1].obj->type == "Prey"))
				{
					cells[i-1][j - 1].obj->mylife = exp_life;
					flag = 1;
				}
				if (((j - 1) >= 0) && ((i + 1) <M) && (cells[i + 1][j - 1].obj != nullptr) && (cells[i + 1][j - 1].obj->type == "Prey"))
				{
					cells[i + 1][j - 1].obj->mylife = exp_life;
					flag = 1;
				}
				if (((j + 1) <N ) && ((i +1) <M) && (cells[i + 1][j + 1].obj != nullptr) && (cells[i + 1][j + 1].obj->type == "Prey"))
				{
					cells[i + 1][j + 1].obj->mylife = exp_life;
					flag = 1;
				}
				if (((j + 1)< N) && ((i - 1) >= 0) && (cells[i - 1][j + 1].obj != nullptr) && (cells[i - 1][j + 1].obj->type == "Prey"))
				{
					cells[i - 1][j + 1].obj->mylife = exp_life;
					flag = 1;
				}
				if (flag == 0)
					cells[i][j].obj->lifeChance--;
			}



		}
	

	
}
void Ocean::Kill()

{
	for (auto it = stuff.begin(); it != stuff.end();)
	{
		if ((((*it)->mylife) >= exp_life) || (((*it)->lifeChance) <= 0))
		{
			(*it)->cell->killMe();

			delete *it;
			it = stuff.erase(it);
		}
		else ++it;
		
		

	}
}
void Ocean::reproduction()
{
	srand(time(0));
	for (auto it = stuff.begin(); it != stuff.end(); it++)
	{
		if (((*it)->mylife) == yearForReproduction)
		{
			if ((*it) ->type == "Prey")	
			{
					int x = rand() % M;
					int y = rand() % N;
					Prey* a = new Prey(&cells[x][y]);
					cells[x][y].setObject(a);
					stuff.push_back(a);
			}
			if ((*it) ->type == "Predator")
			{
				int x = rand() % M;
				int y = rand() % N;
				Predator* a = new Predator(&cells[x][y]);
				cells[x][y].setObject(a);
				stuff.push_back(a);
			}
		}
	}
}