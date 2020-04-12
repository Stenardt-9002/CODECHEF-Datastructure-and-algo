
#include <iostream>
#include <stdio.h>
using namespace std;


static int stepx_1[8] = {1,1,2,2,-1,-1,-2,-2};
static int stepy_1[8] = {2,-2,1,-1,2,-2,1,-1};
 int board1[8][8] ;

int allowedem(int x,int y)
{
  if((x>=0 && y>=0)&&(x<8 &&y<8)&&(board1[x][y]<0))
  {
    return 1;
  }
  return 0;
}

int getDgree1(int x,int y)
{
  int dgreevar = 0;
    for (int i = 0; i < 8; i++)
    {
      if (allowedem(x+stepx_1[i],y+stepy_1[i]))
      {
        dgreevar++;
      }
    }
    return dgreevar;
}





int nextAlloance(int *nexposx,int *nexposy)
{
  int idexmin = -1;
  int min_deg = 9,nextx,nexty;
  int tempdegree,idexiter;

  int sta1rt = rand()%8;
  for (int cntvar = 0; cntvar < 8; cntvar++)
  {
      idexiter = (sta1rt+cntvar)%8;
      nextx = *nexposx+stepx_1[idexiter];
      nexty = *nexposy+stepy_1[idexiter];
      tempdegree = getDgree1(nextx,nexty);
      if (allowedem(nextx,nexty)&&(tempdegree<min_deg))
      {
        idexmin = idexiter;
        min_deg = tempdegree;
      }

  }


  if (idexmin==-1)
  {
    return 0;


  }

  nextx = *nexposx+stepx_1[idexmin];
  nexty = *nexposy+stepy_1[idexmin];


  board1[nextx][nexty] = board1[*nexposx][*nexposy]+1;

  *nexposx = nextx;*nexposy = nexty;
  return 1;

}


int completed1(int curx,int cury,int nexx,int nexy)
{
  for (int k1 = 0; k1 < 8; k1++) {
    if ((curx+stepx_1[k1] == nexx)&&(cury+stepy_1[k1]==nexy))
    {
      return 1;
    }
  }
  return 0;
}




int pathfinding()
{
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++)
    {
      board1[i][j] = -1;

    }
  }

  int currx = rand()%8;
  int curry = rand()%8;

  int nextx = currx,nexty = curry;

  board1[nextx][nexty] = 1;

  for (size_t ij = 0; ij < 63; ij++) {
    if (nextAlloance(&nextx,&nexty)==0)
    {
      return 0;
    }
  }


  // if not circled
  if (completed1(nextx,nexty,currx,curry)==0)
  {
    /* code */
    return 0;
  }

std::cout  << '\n';
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      cout<<" "<<board1[i][j];

    }
    cout<<endl;
  }


  return 1;
}



 int main(int argc, char const *argv[])
 {
   srand(time(NULL));
   while (!pathfinding())
   {
     ;
   }


   return 0;
 }
