
// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


vector<int> bfsOfGraph(int V, vector<int> adj[]) 
{
    vector<bool> visited(V,false);
    int src = 0; 
    queue<int> q1 ;
    q1.push(src);
    visited[src] = true;
    int fronttop ;
    vector<int> ans1 ;
    while (!q1.empty())
    {
        fronttop = q1.front();
        ans1.push_back(fronttop);
        q1.pop();
        for (auto neig : adj[fronttop])
            if(!visited[neig])
            {
                visited[neig] = true ;
                q1.push(neig);
            }
    }
    return ans1 ;

}





 vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        
        
          
        vector<int>adj1[V];
        for (int i1 = 0; i1 < V; i1++)
        {
            for (int j1 = 0; j1 < V; j1++)
            {
                
                adj1[i1].push_back(0);
            }
        }

        for(int i1 =0;i1<V;i1++)
        {
            for(int j1=0;j1<adj[i1].size();j1++)
            adj1[i1][adj[i1][j1]] = 1;
            // cout<<" "<<adj[i1][j1];
            // cout<<endl;
        }
        
        vector<bool> bvsited1(V,false);
        int src = 0;
        queue<int>q1 ;
        q1.push(src);
        // bvsited1[src] = true ;
        vector<int> ans1 ;
        // ans1.push_back(src) ;
        int nodes1 ;
        while (!q1.empty())
        {
            nodes1 = q1.front();
            q1.pop();
            if(!bvsited1[nodes1])
                {
                ans1.push_back(nodes1);
                bvsited1[nodes1] = true  ;
                }
            for (int i1 = 0; i1 < V; i1++)
            {
                if (i1!=nodes1 && adj1[nodes1][i1]==1 && !bvsited1[i1] ) //not a child 
                {
                    // bvsited1[i1] = true ;
                    q1.push(i1) ;
                    // ans1.push_back(i1);
                }
                
            }
            
            // ans1.push_back();

        }
        return ans1;
        
    }



