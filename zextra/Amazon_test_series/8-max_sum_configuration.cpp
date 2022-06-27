

// https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/0/?track=amazon-arrays&batchId=192
#include <bits/stdc++.h>
#include<ext/pbcumu_valds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


int max_sum(int A[],int N)
{
    //Your code here
    int sum_val = 0,cumu_val=0 ;

    for(int i1 = 0 ; i1<N ; i1++)
      sum_val+=(A[i1]*i1);


    for(int i1 = 0 ; i1<N ; i1++)
        cumu_val+=(A[i1]);

    int ans1 = sum_val, next_val ;
    for (int i1 = 1; i1 < N; i1++)
    {
      next_val = sum_val - (cumu_val-A[i1-1]) + (A[i1-1]*(N-1));
      sum_val = next_val ;
      ans1 = max(ans1,next_val);
    }
    return ans1 ;

}
