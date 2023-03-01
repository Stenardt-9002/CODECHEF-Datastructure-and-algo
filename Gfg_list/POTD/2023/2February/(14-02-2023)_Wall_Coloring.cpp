// https://practice.geeksforgeeks.org/problems/51b266505221b97522b1d2c86ddad1868a54831b/1















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
    int minCost(vector<vector<int>> &arr, int N) {
        // Write your code here.
        vector<vector<int>>dp(N+1,vector<int>(3,0));
        
        for(auto i=1;i<=N;i++){
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+arr[i-1][0];
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+arr[i-1][1];
            dp[i][2]=min(dp[i-1][0],dp[i-1][1])+arr[i-1][2];
        }
        
        return min(dp[N][0],min(dp[N][1],dp[N][2]));
    }
};