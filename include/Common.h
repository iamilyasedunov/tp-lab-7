#ifndef _COMMON_H_
#define _COMMON_H_
#include <iostream>
#include <iterator>
//#include<windows.h>
#include <cstdlib>
#include <time.h>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
#include <stdio.h>

using namespace std;
typedef size_t coord_t;
struct Pair
{
	coord_t x; // 0..M-1
	coord_t y; // 0..N-1
};

const size_t N =15;
const size_t M = 15;
const int exp_life =30;
const int chance =17;
const int yearForReproduction =17;
#endif