// https://practice.geeksforgeeks.org/problems/1a4b617b70f0142a5c2b454e6fbe1b9a69ce7861/1















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





void dfs_u(vector<vector<int>>& adj , int src , vector<int>&visited , vector<int>&path)
{
    path.push_back(src);
    visited[src]++ ;
    for(auto child : adj[src])
        if(!visited[child])
            dfs_u(adj , child , visited , path);
}

class Solution {
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) 
    {
        // code here
        vector<int> visited(V+1 , 0);
        int ans = 0 ;
        for (int i = 1; i<=V; i++)
        if(!visited[i])
        {
            vector<int> path ;
            dfs_u(adj , i , visited , path) ;
            bool notconnected = true ;
            for (int j = 0; j < path.size(); j++)
                if(adj[path[j]].size()< path.size()-1)
                {
                    notconnected = false ;
                    break ;
                }

            if(notconnected)
                ans++ ;
        }
        
        return ans ; 
    }
};


