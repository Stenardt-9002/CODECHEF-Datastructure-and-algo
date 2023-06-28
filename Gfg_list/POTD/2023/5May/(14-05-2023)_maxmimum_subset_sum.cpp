// https://practice.geeksforgeeks.org/problems/e047b92794316450814b29de56cc9c6ec18371b7/1






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;







class Solution 
{

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) 
    {
        // code here
        vector<int>dp1(2,0),dp2(2,0);
        dp1[0] = 0 ;
        dp1[1] = A[0];
        for(int i = 1 ; i<N ; i++)
        {
            dp2[1] = A[i]+max(dp1[0],dp1[1]);
            dp2[0] = dp1[1];
            dp1 = dp2 ;
        }
        return max(dp1[0],dp1[1]);
    }
};



















