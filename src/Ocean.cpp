//
// CreatToed by Илья on 06.06.2019.
//

#include <random>
#include "Ocean.h"
#include "Stone.h"
#include "Object.h"
#include "common.h"

using namespace std;

Ocean::Ocean()
{
    cells = new Cell*[N];
    for (size_t i = 0; i < N; i++)
    {
        cells[i] = new Cell[M];
        for (size_t j = 0; j < M; j++)
            cells[i][j].init({i, j}, this);
    }
}
Ocean::~Ocean()
{
    for (int i = 0; i < N; i++)
        delete[] cells[i];
    delete[] cells;
    for (auto obj : stuff)
        delete obj;
}

void Ocean::print() const
{
    int countPrey = 0, countPredator = 0, countStone = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) {
            if (cells[i][j].getObject()) {
                if (cells[i][j].getObject()->getSymbol() == 'f') {
                    countPrey++;
                }
                if (cells[i][j].getObject()->getSymbol() == 'S') {
                    countPredator++;
                }
                if (cells[i][j].getObject()->getSymbol() == '#') {
                    countStone++;
                }
                cout << cells[i][j].getObject()->getSymbol() << " ";
            }
            else {
                cout << ". ";
            }
        }
        cout<<endl;
    }
    cout<<"prey: "<<countPrey<<" predator: "<<countPredator<<" stone: "<<countStone<<endl;
}

void Ocean::addObjects(ObjType type, unsigned int amount)
{
    for (int i = 0; i < amount;)
    {
        auto x = rand() % N;
        auto y = rand() % M;
        if (cells[x][y].getObject())
            continue;
        Object* obj = nullptr;
        switch(type)
        {
            case ObjType::PREDATOR:
                obj = new Predator(&cells[x][y]);
                break;
            case ObjType::PREY:
                obj = new Prey(&cells[x][y]);
                break;
            case ObjType::STONE:
                obj = new Stone(&cells[x][y]);
				break;
            default:
                break;
        }
        cells[x][y].setObject(obj);
        stuff.push_back(obj);
        i++;
    }
}

void Ocean::addStuff(Object *obj)
{
    stuff.push_back(obj);
}

void Ocean::eraseObject(Object *obj)
{
    obj->getCell()->killMe();
}

Cell* Ocean::findEmpty(Pair crd)
{
    random_device rand;
    for (int i = 0; i < Search_Attempts; i++)
    {
        size_t x_ = crd.x + rand() % 3 - 1;
        size_t y_ = crd.y + rand() % 3 - 1;
        if (x_ < N && y_ < M)
            if (cells[x_][y_].getObject() == nullptr)
                return &cells[x_][y_];
    }

    return nullptr;
}

Cell* Ocean::findPrey(Pair crd)
{
    random_device rand;
    for (int i = 0; i < Search_Attempts; i++)
    {
        size_t x_ = crd.x + rand() % 3 - 1;
        size_t y_ = crd.y + rand() % 3 - 1;

        if (x_ < N && y_ < M)
            if (cells[x_][y_].getObject() && cells[x_][y_].getObject()->getType() == ObjType::PREY)
                return &cells[x_][y_];
    }
    return nullptr;
}
void Ocean::start()
{
    auto i = stuff.begin();
    for (; i != stuff.end(); i++)
    {
        if(!(*i)->live())
        {
            eraseObject(*i);
            stuff.erase(i++);
        }
    }

}