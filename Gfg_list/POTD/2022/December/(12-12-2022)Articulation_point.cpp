
// https://practice.geeksforgeeks.org/problems/shortest-path-by-removing-k-walls/1












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

    void dfs_util(int src , int parent , vector<int> adj[],vector<bool> &visited, vector<int> &time_f, vector<int> &lowest ,int &timer ,vector<bool> &ans  )
    {
        int children = 0 ;
        visited[src] = true ;
        lowest[src] = time_f[src] = ++timer ;


        for (auto child : adj[src])  
        {
            if(!visited[child])
            {
                children++ ;
                this->dfs_util(child , src , adj , visited , time_f , lowest , timer , ans);
                lowest[src] = min(lowest[src] , lowest[child]);

                if(parent!=-1 && lowest[child]>=time_f[src])
                    ans[src] = true ;
            }
            else if(child!=parent)
                lowest[src] = min(lowest[src] , time_f[child]);
        }
        
        if(parent==-1 && children>1)
            ans[src] = true ;

    }

    vector<int> articulationPoints(int V, vector<int>adj[]) 
    {
        // Code here
                vector<int> time_f(V,0) , lowest(V,0);
        vector<bool> visited(V,false) , ans(V,false);

        int timer = 0 , parent = -1;

        for (int i = 0; i < V; i++)
            if(!visited[i])
                this->dfs_util(i , parent , adj ,visited  , time_f ,lowest , timer ,ans);
        

        vector<int>final_ans ;
        for (int i = 0; i < V; i++)
            if (ans[i])
                final_ans.push_back(i);
        if(final_ans.size()==0)
            return {-1} ;
            
        return final_ans ;

    }
};



