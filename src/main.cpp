#include "Ocean.cpp"

int main(){

    auto * ocean = new Ocean(100);

    ocean->print(cout);

    for (int i = 0; i < 100; i++){

        ocean->run();
        ocean->print(cout);

    }

    return 0;

}