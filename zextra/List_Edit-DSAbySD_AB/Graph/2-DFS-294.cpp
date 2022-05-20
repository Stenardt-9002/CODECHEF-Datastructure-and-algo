
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



void DFS_util(int src , int V , vector<bool>&visited , vector<int> adj[] , vector<int> &ans1)
{
    visited[src] = true ;
    ans1.push_back(src);
    for (auto neig : adj[src])
        if(!visited[neig])    
            DFS_util(neig,V,visited,adj,ans1);  
}


vector<int> dfsOfGraph(int V, vector<int> adj[]) 
{
    vector<bool> visited(V,false) ;
    vector<int> answer ;
    DFS_util(0,V,visited,adj,answer);
    return answer ;
}

/*
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        bool *visited  = new bool[V];
        vector<int> answer ;
        for(int i=0;i<V;i++)
        {
            visited[i] = 0;//no one visted yet ;
        }
        DFS_util(0,V,visited,adj,answer);
        
        return answer ;
        
    }
    void DFS_util(int src, int V , bool * &visited , vector<int> adj[],vector<int> &answer)
    {
        visited[src] = 1 ;
        
        answer.push_back(src) ;
        
        for(auto i1=adj[src].begin() ;i1!=adj[src].end();i1++)
        {
            if(!visited[*i1]){ DFS_util(*i1,V,visited,adj,answer) ;}
        }
        
        
    }
*/




