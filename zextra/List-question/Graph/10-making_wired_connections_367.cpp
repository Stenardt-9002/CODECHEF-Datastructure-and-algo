
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/


#include<bits/stdc++.h>
using namespace std;


void dfs_throughgraph(int src , vector<bool> &visted , vector<int>graph1[])
{
    visted[src]=true;
    //now rest of componenets
    for (auto i1 = graph1[src].begin(); i1 !=graph1[src].end(); i1++)
    {
        if (!visted[*i1])
        {
            dfs_throughgraph(*i1,visted,graph1);
        }
        
    }
    


}



int get_numofcomponenet(int n , vector<vector<int>>& connections)
{
    int numofcomponenets = 0;
    vector<bool>visited1(n,false ) ;

    vector<int>graph1[n];
    for (int i1 = 0; i1 < connections.size(); i1++)
    {
        graph1[connections[i1][0]].push_back(connections[i1][1]);
        graph1[connections[i1][1]].push_back(connections[i1][0]);
        
    }
    //all vertices
    for (int i1 = 0; i1 < n; i1++)
    {
        if (!visited1[i1])
        {
            dfs_throughgraph(i1,visited1,graph1);
            numofcomponenets++;
        }
    }
    return numofcomponenets;
}




int makeConnected(int n, vector<vector<int>>& connections) 
{
    if (connections.size()<n-1)
    {
        // #cant make one compnent 
        return -1;
    }

    int numofcompo = get_numofcomponenet(n,connections) ;
    return numofcompo-1;
}



