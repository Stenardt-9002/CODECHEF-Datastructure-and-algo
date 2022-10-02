#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
  int n,m;

  std::cin >> n>>m;
  string inputeachrow;

  int **arr1 = new int*[2100];
  // int arr1[2100][2100];
  for (int i = 0; i < n; i++)
  {
    arr1[i] = new int[2100];
    std::cin >> inputeachrow;
    for (int j = 0; j < m; j++)
    {
      // cin>>arr1[i][j];
      // std::cout << "HIT" << '\n';
      arr1[i][j] = inputeachrow[j]-'0';
    }

  }
  //continuous one technique

  int dp1[2100];
  int whentoend = 0,asn1;
  memset(dp1,0,2100);
  for (int i = n-1; i >= 0; i--)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr1[i][j]==1)
      {
        dp1[j]++;//continuous ones under i,j (we go from right because consective matters (upper limit))
      }
      else
      {
        dp1[j] = 0;
      }


    }

    whentoend = 0;//contains indiviual maximum 1 for each x and y
    for (int j = 0; j < m; j++)
    {
      if (whentoend+1<dp1[j])
      {
        whentoend++;
      }
      else
      {
        whentoend = dp1[j];//min of C{X}{Y} and AR1[X][Y-1]+1
      }

      asn1 += whentoend;


    }



  }

  std::cout << asn1 << '\n';



  return 0;
}
