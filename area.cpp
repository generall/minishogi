#include "area.h"

void Area::reCalcAtt()
{
	resetAtt();
	for(uint i=0;i<5;i++)
	{
		for(uint j=0;j<5;j++)
		{
			int x=i;
			int y=j;
			uint ci=i;
			uint cj=j;
			switch(map[i][j].piece)
			{

				case KING:
					setAtt(x-1,y,true);
					setAtt(x-1,y-1,true);
					setAtt(x-1,y+1,true);
					setAtt(x,y-1,true);
					setAtt(x,y+1,true);
					setAtt(x+1,y,true);
					setAtt(x+1,y-1,true);
					setAtt(x+1,y+1,true);	
					break;
				case GOLD:
					setAtt(x-1,y,true);
				//	setAtt(x-1,y-1,true);
					setAtt(x-1,y+1,true);
					setAtt(x,y-1,true);
					setAtt(x,y+1,true);
					setAtt(x+1,y,true);
				//	setAtt(x+1,y-1,true);
					setAtt(x+1,y+1,true);	
					break;
				case SILV:
				//	setAtt(x-1,y,true);
					setAtt(x-1,y-1,true);
					setAtt(x-1,y+1,true);
				//	setAtt(x,y-1,true);
					setAtt(x,y+1,true);
				//	setAtt(x+1,y,true);
					setAtt(x+1,y-1,true);
					setAtt(x+1,y+1,true);
					break;
				case UPSILV:
					setAtt(x-1,y,true);
				//	setAtt(x-1,y-1,true);
					setAtt(x-1,y+1,true);
					setAtt(x,y-1,true);
					setAtt(x,y+1,true);
					setAtt(x+1,y,true);
				//	setAtt(x+1,y-1,true);
					setAtt(x+1,y+1,true);	
					break;
				case UPBISH:
					setAtt(x-1,y,true);
					setAtt(x-1,y-1,true);
					setAtt(x-1,y+1,true);
					setAtt(x,y-1,true);
					setAtt(x,y+1,true);
					setAtt(x+1,y,true);
					setAtt(x+1,y-1,true);
					setAtt(x+1,y+1,true);
					
					
				case BISH:
					ci=i;
					cj=j;
					while(inRange(++ci,++cj))
					{
						setAtt(ci,cj,true);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(--ci,++cj))
					{
						setAtt(ci,cj,true);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(++ci,--cj))
					{
						setAtt(ci,cj,true);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(--ci,--cj))
					{
						setAtt(ci,cj,true);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					break;
					
				case UPROCK:
					setAtt(x-1,y,true);
					setAtt(x-1,y-1,true);
					setAtt(x-1,y+1,true);
					setAtt(x,y-1,true);
					setAtt(x,y+1,true);
					setAtt(x+1,y,true);
					setAtt(x+1,y-1,true);
					setAtt(x+1,y+1,true);	
				case ROCK:
					ci=i;
					cj=j;
					while(inRange(++ci,cj))
					{
						setAtt(ci,cj,true);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(ci,++cj))
					{
						setAtt(ci,cj,true);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(ci,--cj))
					{
						setAtt(ci,cj,true);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(--ci,cj))
					{
						setAtt(ci,cj,true);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					break;
				case PAWN:
					setAtt(x,y+1,true);
					break;
				case UPPAWN:
					setAtt(x-1,y,true);
				//	setAtt(x-1,y-1,true);
					setAtt(x-1,y+1,true);
					setAtt(x,y-1,true);
					setAtt(x,y+1,true);
					setAtt(x+1,y,true);
				//	setAtt(x+1,y-1,true);
					setAtt(x+1,y+1,true);	
					break;
				case KING + 128:
					setAtt(x-1,y,false);
					setAtt(x-1,y-1,false);
					setAtt(x-1,y+1,false);
					setAtt(x,y-1,false);
					setAtt(x,y+1,false);
					setAtt(x+1,y,false);
					setAtt(x+1,y-1,false);
					setAtt(x+1,y+1,false);	
					break;
				case GOLD + 128:
					setAtt(x-1,y,false);
					setAtt(x-1,y-1,false);
				//	setAtt(x-1,y+1,false);
					setAtt(x,y-1,false);
					setAtt(x,y+1,false);
					setAtt(x+1,y,false);
					setAtt(x+1,y-1,false);
				//	setAtt(x+1,y+1,false);	
					break;
				case SILV + 128:
				//	setAtt(x-1,y,false);
					setAtt(x-1,y-1,false);
					setAtt(x-1,y+1,false);
					setAtt(x,y-1,false);
				//	setAtt(x,y+1,false);
				//	setAtt(x+1,y,false);
					setAtt(x+1,y-1,false);
					setAtt(x+1,y+1,false);
					break;
				case UPSILV + 128:
					setAtt(x-1,y,false);
					setAtt(x-1,y-1,false);
				//	setAtt(x-1,y+1,false);
					setAtt(x,y-1,false);
					setAtt(x,y+1,false);
					setAtt(x+1,y,false);
					setAtt(x+1,y-1,false);
				//	setAtt(x+1,y+1,false);	
					break;
				case UPBISH + 128:
					setAtt(x-1,y,false);
					setAtt(x-1,y-1,false);
					setAtt(x-1,y+1,false);
					setAtt(x,y-1,false);
					setAtt(x,y+1,false);
					setAtt(x+1,y,false);
					setAtt(x+1,y-1,false);
					setAtt(x+1,y+1,false);	
				case BISH + 128:
					ci=i;
					cj=j;
					while(inRange(++ci,++cj))
					{
						setAtt(ci,cj,false);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(--ci,++cj))
					{
						setAtt(ci,cj,false);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(++ci,--cj))
					{
						setAtt(ci,cj,false);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(--ci,--cj))
					{
						setAtt(ci,cj,false);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					break;
				case UPROCK + 128:
					setAtt(x-1,y,false);
					setAtt(x-1,y-1,false);
					setAtt(x-1,y+1,false);
					setAtt(x,y-1,false);
					setAtt(x,y+1,false);
					setAtt(x+1,y,false);
					setAtt(x+1,y-1,false);
					setAtt(x+1,y+1,false);	
				case ROCK + 128:
					ci=i;
					cj=j;
					while(inRange(++ci,cj))
					{
						setAtt(ci,cj,false);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(ci,++cj))
					{
						setAtt(ci,cj,false);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(ci,--cj))
					{
						setAtt(ci,cj,false);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					ci=i;
					cj=j;
					while(inRange(--ci,cj))
					{
						setAtt(ci,cj,false);
						if(map[ci][cj].taken)
						{
							break;
						}
					}
					break;
				case PAWN + 128:
					setAtt(x,y-1,false);
					break;
				case UPPAWN + 128:
					setAtt(x-1,y,false);
					setAtt(x-1,y-1,false);
				//	setAtt(x-1,y+1,false);
					setAtt(x,y-1,false);
					setAtt(x,y+1,false);
					setAtt(x+1,y,false);
					setAtt(x+1,y-1,false);
				//	setAtt(x+1,y+1,false);	
					break;
					

			}
		}
	}
}