
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1/




#include <bits/stdc++.h>
using namespace std;



bool BFS_util(int src ,int V , vector<int>adj[],vector<int> &whatvolor,queue<int> &q1)
{
    int des ;
    while (!q1.empty())
    {
        src = q1.front() ;
        q1.pop() ;

        for (auto i1 = adj[src].begin(); i1 !=adj[src].end(); i1++)
        {
            des = *i1 ;
            if (whatvolor[des]==whatvolor[src])
            {
                return false ;
            }
            if (whatvolor[des]==-1)
            {
                whatvolor[des] = 1-whatvolor[src];
                q1.push(des);
            }
        }
    }
    return true ;
}






bool isBipartite(int V, vector<int>adj[])
{
    vector<int> whatvolor(V,-1);
    queue<int> q1 ;

    for (int vertex1 = 0; vertex1 < V; vertex1++)
    {
        if (whatvolor[vertex1]==-1)
        {
            whatvolor[vertex1] = 1 ; //src coloured red
            q1.push(vertex1);
            if (BFS_util(vertex1,V,adj,whatvolor,q1)==false)
            {
                return false ;
            }
            
        }
        
    }
    return true ;
}

int main(int argc, char const *argv[])
{
    int V ,E ;
    V=4,E=8 ;
    vector<int> adj[V] ;
    adj[0] = {1,3} ;
    adj[1] = {1,3} ;
    adj[2] = {1,3} ;
    adj[3] = {0,2} ;



    return 0;
}




