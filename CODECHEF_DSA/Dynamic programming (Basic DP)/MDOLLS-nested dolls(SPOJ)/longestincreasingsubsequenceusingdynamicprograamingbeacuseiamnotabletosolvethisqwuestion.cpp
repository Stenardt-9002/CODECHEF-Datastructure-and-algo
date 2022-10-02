// L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef signed long long int lldi;


int lis(int arr1[],int sieaz)
{

  int dp1[sieaz] ;
  memset(dp1,1,sieaz*(sizeof(int)));
  // for (int i = 0; i < sieaz; i++)
  // {
  //
  //   std::cout << dp1[i] << '\n';
  // }

  // starting index 0 will have dp1 value 1
  dp1[0] = 1;
  for (int i = 1; i < sieaz; i++)
  {
    dp1[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if (arr1[j]<arr1[i] && dp1[i]<dp1[j]+1)
      {
        dp1[i] = dp1[j]+1;
      }

    }
  }


return *max_element(dp1,dp1+sieaz);




}



int main(int argc, char const *argv[])
{


  int arr1[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int size = sizeof(arr1)/sizeof(arr1[0]);
    printf("Ansswer  %d", lis( arr1, size ));
    return 0;


  return 0;
}
