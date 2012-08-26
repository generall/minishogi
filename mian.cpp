#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <limits.h>

using namespace std;

/*
#define NOP 0
#define KING 1
#define GOLD 2
#define SILV 3
#define UPSILV 4
#define BISH 5 
#define UPBISH 6
#define ROCK 7
#define UPROCK 8
#define PAWN 9
#define UPPAWN 10
*/

#include "area.h"

typedef size_t uint;
typedef unsigned char byte;



int main()
{
	
	Area a;
	a.addPiece(1,1,ROCK);
	a.addPiece(2,1,GOLD);
	a.print();
	return 0;
	
}