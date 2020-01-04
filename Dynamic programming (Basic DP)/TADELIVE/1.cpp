#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
char z;

  long long int x,y,n;
  long long int arr1x[10001];
  long long int arr1y[10001];
  // long long int masxdp[10001][10001];
  int **masxdp = new int*[10001];
  for (int i = 0; i < 10001; i++)
  {
    masxdp[i] = new int[10001];
  }
  // std::cout << "\n\nREACHED" << '\n';

  cin>>n>>x>>y;
  for (long long int i = 0; i < n; i++)
  {
    cin>>arr1x[i];
  }

  for (long long int i = 0; i < n; i++)
  {
    cin>>arr1y[i];
  }

for (long long int i = 0; i < n; i++)
{
  for (long long int j = 0; j < n; j++)
  {
    masxdp[i][j] = 0;
  }
}

  // std::cout << "\n\nREACHED" << '\n';


//use dp because greedy is a sucks  `Mahan Gandi

  long long int xord = 0,yord = 0;

  for (long long int i = 0; i < n; i++) // i is for order no traversal
  {

    for (long long int j = 0; j <=i; j++) //j is number of order x has y will have i-j
    {
      // std::cout << "\n\nREACHED" << '\n';

      xord = 0;yord = 0;
      if (j<x)
      {
        xord = masxdp[i][j]+arr1x[i];
      }

      if (i-j<y)
      {
        yord = masxdp[i][j+1]+arr1y[i];

      }

      masxdp[i][j] = xord;
      if (masxdp[i][j]<yord)
      {
        masxdp[i][j] = yord;
      }



      // std::cin >> z;
    }
  }

//
// for (long long int i = 0; i < n; i++)
// {
//   for (long long int j = 0; j <= i; j++)
//   {
//     std::cout << "\nCode" << '\n';
//     std::cout << "i"<<i << '\n';
//     std::cout << "j"<<j << '\n';
//     std::cout << "masxdp[i][j]"<<masxdp[i][j] << '\n';
//   }
//
// std::cout << "\n\n" << '\n';


// }


long long int ans = 0,temp ;

for (long long int j = 0; j < n; j++)
{
  temp = masxdp[j][0];
  for (long long int i = 1; i < x; i++)
  {
    if (temp<masxdp[j][i])
    {
      temp = masxdp[j][i];
    }

  }

  ans = ans+temp;



}

std::cout << ans << '\n';


for (long long int i = 0; i < 10001; i++)
{
  delete[] masxdp[i];

}
delete[] masxdp;



  return 0;
}
