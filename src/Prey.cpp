#include "Prey.h"
#include "Ocean.h"
using namespace std;

Prey::Prey(Cell* cell_, Ocean* ocean_):Stone(cell_, ocean_)
{
    life = 25;
    tire_waiting = life / 3;
    type = PREY;
    ocean = ocean_;
    vision = new ViewField(cell, 4, ocean, this);
    speed = 1;
}

Prey::~Prey()
{
    //dtor
}

bool Prey::Update()
{
    bool alive = false;
    life--;
    if (life <=0)
    {
        return alive;
    }
    if (is_tire)
    {
        tire_counter--;
        if (tire_counter <= 0)
        {
            is_tire = false;
        }
    }

    for (int i = 0; i < speed; i++)
    {
        Cell* target = 0;
        target = vision->Observe();
        if (target == 0)
        {
            if (current_aim.remaining <= 0)
            {
                ChooseNewAim();
            }
            int x = cell->x + current_aim.x;
            int y = cell->y + current_aim.y;

            //spherical ocean
            if (x < 0) x = ocean->size_x-1;
            else if (x >= ocean->size_x) x = 0;
            if (y < 0) y = ocean->size_y-1;
            else if (y >= ocean->size_y) y = 0;

            target = ocean->GetCell(x, y);
            current_aim.remaining--;
        }

        alive = MoveTo(target);
    }

    return alive;
}

void Prey::ChooseNewAim()
{
    current_aim.remaining = 0;
    current_aim.x = 0;
    current_aim.y = 0;

    if (rand()%2 == 0)
    {
        //move horizontal
        if (rand()%2 == 0)
        {
            current_aim.x = 1;
        }
        else
        {
            current_aim.x = -1;
        }
    }
    else
    {
        //move vertical
        if (rand()%2 == 0)
        {
            current_aim.y = 1;
        }
        else
        {
            current_aim.y = -1;
        }
    }
    current_aim.remaining = tire_waiting;
}

bool Prey::MoveTo(Cell* target)
{
    if ((cell->x - target->x != 1 && cell->x - target->x != -1)&&
        (cell->y - target->y != 1 && cell->y - target->y != -1))
    {
        cout<<"obj| x:"<<cell->x<<" y:"<<cell->y<<endl;
        cout<<"target| x:"<<target->x<<" y:"<<target->y<<endl;
        //system("pause");
    }
    bool movement = false;
    if(ocean->MoveObj(this, target))
    {
        vision->SetField(cell);
    }
    (life <= 0)?(movement = false):(movement = true);

    return movement;
}

void Prey::Damage(int num)
{
    if (num >= 0)
    {
        life -= num;
        current_aim.remaining = 0;
    }
    else
    {
        life = -1;
    }
}

void Prey::Tired()
{
    is_tire = true;
    tire_counter = tire_waiting;
}
