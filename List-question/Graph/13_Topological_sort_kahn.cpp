

// https://practice.geeksforgeeks.org/problems/topological-sort/1



#include <bits/stdc++.h>
using namespace std;





class Graph1
{

public:
    int v; vector<int>adj[] ;

    Graph1(int V);

};






vector<int> topoSort(int V, vector<int> adj[]) 
{


    vector<int> indegree(V,0);
    vector<int>asn1 ;


    for (int i1 = 0; i1 < V; i1++)
    {
        for (auto itr = adj[i1].begin() ;itr!=adj[i1].end();itr++  )
        {
            indegree[*itr]++;
        }
    }

    queue<int> q1 ; 
    for (int i1 = 0; i1 < V; i1++)
    {
        q1.push(i1) ;
    }
    
    int count_nodes = 0;
    int src, des ;
    while (!q1.empty())
    {
        src = q1.front() ; q1.pop() ; asn1.push_back(src) ;
        //look at src neighbouts 
        for (auto itr = adj[src].begin() ;itr!=adj[src].end();itr++  )
        {
            if(--indegree[*itr]==0)
            {
                q1.push(*itr) ;// indegee 0 means that all the prequist is done : itr prequiste is source 
            }
        }
        count_nodes++;

    }
    if (count_nodes!=V)
    {
        return {}; // cycle 
    }
    return asn1 ;
}




