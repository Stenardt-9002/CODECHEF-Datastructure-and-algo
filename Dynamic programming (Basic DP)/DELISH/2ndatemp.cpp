#include <iostream>
#include <cmath>
#include <algorithm>
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

using namespace std;

long long pos1(long long a)
{
  if (a<0)
  {
    return -a;
  }
  return a;
}
long long leftmin[1000010],leftmax[1000010],rightmax[1000010],rightmin[1000010],daat[1000010];


int main(int argc, char const *argv[])
{
  long long ans1;
  int n,t;

  scanf("%d",&t );
  while (t--)
  {
    scanf("%d",&n );
    for (size_t i = 0; i < n; i++)
    {
      cin>>daat[i];

    }

    leftmin[0] = daat[0];
    leftmax[0] = daat[0];


    for (size_t i = 1; i < n; i++)
    {
      leftmin[i] = min(leftmin[i-1],0)+daat[i];
      leftmax[i] = max(leftmax[i-1],0)+daat[i];


    }

    rightmax[0] = daat[n-1];
    rightmin[0] = daat[n-1];

    for (size_t i = n-2; i >=0; i++)
    {
      rightmax[i] = max(rightmax[i],0)+daat[i];
      rightmin[i] = min(rightmin[i],0)+daat[i];
    }

    for (size_t i = 0; i < n-2; i++)
    {
      ans1 = max(ans1,pos1(leftmax[i]-rightmin[i+1]));
      ans1 = max(ans1,pos1(leftmin[i]-rightmax[i+1]));

    }

    printf("\n" );
  printf("%lld",ans1 );


  }



  return 0;
}
