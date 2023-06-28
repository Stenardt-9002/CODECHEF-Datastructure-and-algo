// https://practice.geeksforgeeks.org/problems/09b910559335521654aa2909f86f893447d8f5ba/1










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
    bool makeChanges(int N, int K, int target, vector<int> &coins) 
    {
        // code here
        // vector<vector<vector<int>>>dp1(N+1,vector<vector<int>>(K+1,vector<int>(target+1 , -1)));
        // return recursive_func(target , K , 0 , N , coins,dp1);
        
        
        vector<vector<bool>>dp1(K+1 , vector<bool>(target+1,false));
        dp1[0][0] = true ; 
        for(int i = 0 ; i<N;i++)
            for(int j = 1 ; j<=K ; j++)
                for(int coin = coins[i] ; coin<=target ; coin++)
                    dp1[j][coin] = dp1[j][coin]||dp1[j-1][coin-coins[i]];
        
        return dp1[K][target];
    }
};




