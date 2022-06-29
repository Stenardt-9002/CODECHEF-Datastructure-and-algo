

// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/0/?track=amazon-arrays&batchId=192

#include <bits/stdc++.h>
#include<ext/pbcumu_valds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


long long trappingWater(int arr[], int n)
{
    // code here
    long long int sum1 = 0 ;
    std::vector<int> left_sum(n,0);
    std::vector<int> right_sum(n,0);
    int max_val = INT_MIN ;
    for (int i1 = 0; i1 < n; i1++)
    {
      if(max_val<arr[i1])
        max_val = arr[i1];

      left_sum[i1] = max_val ;
    }

    max_val = INT_MIN ;
    for (int i1 = n-1; i1 >=0 ; i1--)
    {
      if(max_val<arr[i1])
        max_val = arr[i1];

      right_sum[i1] = max_val ;
    }

    for (int i1 = 0; i1 < n; i1++)
      if(min(left_sum[i1], right_sum[i1])-arr[i1]>0 )
        sum1+=(min(left_sum[i1], right_sum[i1])-arr[i1]);

    return sum1;
}
