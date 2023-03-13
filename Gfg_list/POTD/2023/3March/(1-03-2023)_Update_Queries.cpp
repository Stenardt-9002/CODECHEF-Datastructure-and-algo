
// https://practice.geeksforgeeks.org/problems/a6528c893d4ab645ec6e0690c7982748385099c8/1







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
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            // code here
            vector<int>ans(N,0);
            vector<vector<int>>dp1(N+1 , vector<int>(17,0));
            for(auto vec : U)
            {
                for(int i=0 ; i<17;i++)
                {
                    int mask = 1<<i ;
                    if(mask&vec[2])
                    {
                        int first = vec[0]-1;
                        int second = vec[1];
                        dp1[first][i]++ ;
                        dp1[second][i]-- ;
                    }
                }
            }
            for(int n = 1;n<N ; n++)
            for(int bits = 0;bits<17;bits++)
                dp1[n][bits]+=dp1[n-1][bits];
                
                
            
            for(int n = 0;n<N;n++)
            {
                int cur = 0 ;
                for(int i=0 ; i<17;i++)
                    if(dp1[n][i]>0) 
                        cur+=(1<<i);
                    
                ans[n] = cur ;
            }
            
            return ans ;
            
        }
};