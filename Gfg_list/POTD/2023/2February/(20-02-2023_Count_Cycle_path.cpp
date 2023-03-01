// # https://practice.geeksforgeeks.org/problems/aa0000a5f710ce8d41366b714341eef644ec7b82/1
// 
















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
















class Solution{   
public:
    int countPaths(int N)
    {
        // code here 
        vector<ll>cur_dp(4,0)  , dp_pre(4,0);
        dp_pre[0] = 1;
        ll prev_row_sum = 1 ; 
        for (int n = 0; n < N; n++)
        {
            ll cur_row_sum = 0 ;
            for (int j = 0; j < 4; j++)
            {
                cur_dp[j] = (mod1+prev_row_sum-dp_pre[j])%mod1;
                cur_row_sum = (cur_row_sum+cur_dp[j])%MOD1;
            }
            prev_row_sum = cur_row_sum ;
            dp_pre = cur_dp ;
        }
        return dp_pre[0];
    }
};