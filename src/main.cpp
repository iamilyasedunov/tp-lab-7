#include "Ocean.h"
#include <conio.h>
#include <unistd.h>
int main()
{
    Ocean ocean;
    ocean.addObjects(ObjType::STONE, 50);
    ocean.addObjects(ObjType::PREY, 130);
    ocean.addObjects(ObjType::PREDATOR, 10);
    std::cout << "\n\n" << std::endl;

    for (int i = 0; i < 8; i++) {
        ocean.start();
        std::cout << "\n\n" << std::endl;
        ocean.print();
    }

    return 0;
}