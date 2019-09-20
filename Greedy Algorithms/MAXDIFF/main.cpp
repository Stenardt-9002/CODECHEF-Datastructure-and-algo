// code sort n items
// highly time consuming
// can be optimised easily
// but i didn't
// cus it your fucking job
#include <iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main() {
	long long int t,i,n,k;
  long long int sum1=0,sum2=0,sum;
  // long int *arr1 = NULL;
	long long int ans;
  cin>>t;
  while (t--)
  {
      cin>>n>>k;
			// arr1 = new long int[n];
			long long int arr1[n];

      sum1 = 0;sum2 = 0;
			sum=0;
      for (i = 0; i < n; i++)
      {
        cin>>arr1[i];
				sum+=arr1[i];
      }
      sort(arr1,arr1+n);
      // for (i = 0; i < n; i++)
      // {
      //     if (i<k)
      //     {
      //       sum1+=arr1[i];
      //     }
			//
      //     else
      //     {
      //       sum2+=arr1[i];
      //     }
			//
      // }
			// if (sum1<sum2)
			// {
			// 	ans = sum2-sum1;
			// }
			// else
			// {
			// 	ans = sum1-sum2;
			// }
			// cout<<sum2-(2*sum1)<<endl;
      // std::cout << endl << '\n';
      // cout<<" sum1 "<<sum1<<endl;
      // cout<<" sum2 "<<sum2<<endl;

			long long int tmp ;
			if (k<(n-k))
			{
				tmp = k;
			}
			else
			{
				tmp = n-k;
			}
			for (i = 0; i < tmp; i++)
			{
				sum1+=arr1[i];
			}

			ans = sum-2*sum1;

				cout<<ans<<endl;
				// delete []arr1;


  }

	// return 0;
}
