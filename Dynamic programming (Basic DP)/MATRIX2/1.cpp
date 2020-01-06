#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
  int n,m;

  std::cin >> n>>m;
  string inputeachrow;

  int **arr1 = new int*[n];
  for (int i = 0; i < n; i++)
  {
    arr1[i] = new int[m];
    for (int j = 0; j < m; j++)
    {
      cin>>arr1[i][j];
      // std::cout << "HIT" << '\n';
    }

  }

int size1 = std::max(n,m);
int *dp1 = new int[size1];
int ansewr = 0;
int end1;
  for (int i = n-1; i >=0; i--)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr1[i][j]==0)
      {
        dp1[j] = 0;

      }
      else
      {
        dp1[j]++;// ones maximum  cntinuos till that i

      }

    }
    end1 = 0;
    for (int j = 0; j < m; j++)
    {
      if (end1<dp1[j])
      {
        ansewr+=end1+1;
        end1+=1;
      }
      else
      {
        ansewr+=dp1[j];
        end1 = dp1[j];
      }

    }



  }

  std::cout << ansewr << '\n';




  return 0;
}
