#include <iostream>
#include <stdlib.h>
typedef long long int lld;

#define INT_MAX 999999


int main(int argc, char const *argv[])
{


  int n = 2, k = 36;
   printf ("nMinimum number of trials in worst case with %d eggs and "
            "%d floors is %d \n", n, k, eggDrop(n, k));

  lld dpslve[n+1][k+1];
 lld answer;
 lld i, j, x;

 for (i = 1; i <= n; i++)
 {
     dpslve[i][1] = 1;
     dpslve[i][0] = 0;
 }

 for (j = 1; j <= k; j++)
     dpslve[1][j] = j;


     for (j = 2; j <= n; j++)
     {
      for (lld a1 = 2; a1 <=k; a1++)
      {
        dpslve[j][a1] = INT_MAX;
        for (lld x1 = 0; x1 < =a1; x1++)
        {
            answer = 1+ max(dpslve[j-1][x1-1],dpslve[j][a1-x1]);
            if (answer<dpslve[j][a1])
            {
              dpslve[j][a1] = answer;

            }

        }


      }
     }



  return 0;
}
