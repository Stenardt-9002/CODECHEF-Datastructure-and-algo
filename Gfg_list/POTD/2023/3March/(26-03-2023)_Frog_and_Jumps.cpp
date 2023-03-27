// https://practice.geeksforgeeks.org/problems/5551749efa02ae36b6fdb3034a7810e84bd4c1a4/1














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
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<bool>dp_v(leaves+1 , 0);
        int ans = leaves ; 
        for(int i = 0 ; i<N; i++)
        {
            int ele = frogs[i];
            if(ele==1)
                return 0 ;
            if(dp_v[ele])
                continue ; 
            for(int itr = ele ; itr<=leaves ; itr+=ele)
                if(!dp_v[itr])
                {
                    ans-- ;
                    dp_v[itr] = true ;
                }
        }
        return ans ;
    }
};