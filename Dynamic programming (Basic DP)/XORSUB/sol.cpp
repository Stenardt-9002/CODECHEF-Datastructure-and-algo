#include<bits/stdc++.h>
using namespace std;
#define INT_BITS 11

int maxSubarrayXOR(int set[], int n,int feltoxor)
{
	// Initialize index of
	// chosen elements
	int index = 0;

	for (int i = INT_BITS-1; i >= 0; i--)
	{
		int maxInd = index;
		int maxEle = INT_MIN;
		for (int j = index; j < n; j++)
		{
			// if ( (set[j] & (1 << i)) != 0	&& (set[j] > maxEle) &&(feltoxor&(1<<i)!=0 ))
      if ( (set[j] & (1 << i)) != 0	&& (set[j] > maxEle))
      {
        maxEle = set[j], maxInd = j;

      }
		}
		if (maxEle == INT_MIN)
		continue;

		swap(set[index], set[maxInd]);
		maxInd = index;

		for (int j=0; j<n; j++)
		{
			if (j != maxInd &&(set[j] & (1 << i)) != 0)
      {
        set[j] = set[j] ^ set[maxInd];

      }
		}

		index++;
	}

	// Final result is
	// XOR of all elements
	int res = 0;
  int x ,y ;
	for (int i = 0; i < n; i++)
		res ^= set[i];
	// return res;
  // std::cout <<"\nres " <<res <<" feltoxor "<<feltoxor << '\n';
  int ans = 0;
  for (int i = 0; i < INT_BITS; i++)
  {
    x = res&(1<<i);
    y = feltoxor&(1<<i);
    // std::cout << "x "<<x << '\n';
    // std::cout << "y "<<y << '\n';

    if (((res&(1<<i))!=0) ||((feltoxor&(1<<i))!=0) )
    {

      ans+=(1<<i);
      // printf("Hit" );

    }


  }

  return ans;

}

// Driver program
int main()
{
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
    	cout << maxSubarrayXOR(set, n,etelemxor);
  }



	return 0;
}
