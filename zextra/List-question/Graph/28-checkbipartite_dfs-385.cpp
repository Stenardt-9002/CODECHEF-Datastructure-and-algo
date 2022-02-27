// https://practice.geeksforgeeks.org/problems/bipartite-graph/1/




#include <bits/stdc++.h>
using namespace std;




bool DFS_util(int src , int V , vector<int>adj[],vector<int> &color)
{
    for (auto des:adj[src])
    {
        if (color[des]==-1)
        {
            color[des] = 1-color[src] ;
            if (DFS_util(des,V,adj,color)==false)
                return false ;
        }
        if(color[des]==color[src])
        {
            return false ;
        }
    }
    return true ;
}



bool isBipartite(int V, vector<int>adj[])
{
    vector<int>color(V,-1);
    // vector<bool>vsited(V,false);// no need for visited
    for (int i1 = 0; i1 < V; i1++)
    {
        if (color[i1]==-1)
        {
            color[i1] = 1;
            if(DFS_util(i1,V,adj,color)==false)
            {
                return false ;
            }
        }
    }
    return true ;
}








