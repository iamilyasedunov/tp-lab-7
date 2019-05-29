#include <iostream>
#include "cstdlib"

#include "Ocean.h"


using namespace std;
int main()
{
    cout << "Hello world!" << endl;
    Ocean caspia(20, 60, 0, 20, 5);
    caspia.Start();
    return 0;
}
