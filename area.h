#ifndef AREA_H_
#define AREA_H_


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <limits.h>
using namespace std;
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


typedef size_t uint;
typedef unsigned char byte;




class Cell
{
public:
	bool wAttaked;
	bool bAttaked;
	bool taken;
	byte piece;
	Cell()
	{
		wAttaked=bAttaked=taken=0;
		piece=0;
	}
};

class Area
{
private:
	vector< vector<Cell> > map;
	
public:
	const int size;
	
	
	bool inRange(int x, int y)
	{
		
		if(x>size - 1 || x<0 || y<0 || y> size - 1)
		{
			return 0;
		}
		return 1;
	}
	
	Area() : size(5)
	{
		for(int i=0;i<size;i++)
		{
			map.push_back(vector<Cell>(size,Cell()));
		}
	}
	void setCell(int x, int y,const Cell& c)
	{
		if(x>size - 1 || x<0 || y<0 || y> size - 1)
		{
			return;
		}
		map[x][y]=c;
	}
	void setAtt(int x, int y, bool w)
	{
		if(x>size - 1 || x<0 || y<0 || y> size - 1)
		{
			return;
		}
		if(w)
		{
			map[x][y].wAttaked=true;
		}else{
			map[x][y].bAttaked=true;
		}
	}
	void resetAtt()
	{
		for(int i=0;i<size;i++)
				{
					for(int j=0;j<size;j++)
					{
						map[i][j].bAttaked=0;
						map[i][j].wAttaked=0;
					}
				}
	}
	void reCalcAtt();
	void print()
	{
		for(int j=0;j<size;j++)
		{
			for(int i=0;i<size;i++)
			{
				if(map[i][j].bAttaked || map[i][j].wAttaked)
				{
					cout<<"1 ";
				}else{
					cout<<"0 ";
				}
			}
			cout<<endl;
		}	
		
	}
	void addPiece(uint x, uint y, uint p)
	{
		if(inRange(x,y))
		{
			map[x][y].piece = p;
			map[x][y].taken = true;
			reCalcAtt();
		}
	}
};
#endif /*AREA_H_*/
