// #include<bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int subsetXOR(int array1[], int n, int feltoxor)
{
	int maxEle = array1[0];
	for (int i=1; i<n; i++)
  {
    if (array1[i] > maxEle)
    {
      		maxEle = array1[i];
    }
  }
	int litmi = (1 << (int)(log2(maxEle) + 1) ) - 1;

	int dp[n+1][litmi+1];

	for (int i=0; i<=n; i++)
	for (int j=0; j<=litmi; j++)
	dp[i][j] = 0;

	dp[0][0] = 1;

	for (int i=1; i<=n; i++)
    {

    for (int j=0; j<=litmi; j++)
      {
        dp[i][j] = dp[i-1][j] + dp[i-1][j^array1[i-1]];
      }
    }

  maxEle = 0;
  int onto=0;
  for (int i=0;i<litmi+1 ;i++ )
  {
    if(dp[n][i]>0)
    {
      onto = i ^ feltoxor;
      if (onto>maxEle)
      {
        maxEle = onto;
      }
    }
  }

  return maxEle;

}




int main()
{
	// int array1[] = {1, 2, 3, 4, 5};


  int testcaes = 0;

  int n,etelemxor;
  // int set[] = {17,5,7,23,22,3};
  // n = sizeof(set) / sizeof(set[0]);
  int set[1000];
  std::cin >> testcaes;
  while (testcaes--)
  {
    cin>>n>>etelemxor;
    for (int i = 0; i < n; i++)
    {
      cin>>set[i];

    }




      // cout << "Max subset XOR is ";
      cout << subsetXOR(set, n,etelemxor);
  }





	return 0;
}
