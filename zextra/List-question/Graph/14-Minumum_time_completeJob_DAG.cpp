

// https://practice.geeksforgeeks.org/problems/topological-sort/1





#include <bits/stdc++.h>
using namespace std;


//BFS Kahn algorithm

void addEdge(int u , int v,vector<int>graph[],vector<int> &indegree)
{
    graph[u].push_back(v) ; indegree[v]++;
}

vector<int> georder(int V, int E, vector<int>graph[],vector<int> &indegree)
{
    vector<int> asnwer(V);
    queue<int> q1 ;
    for (int i1 = 0; i1 < V; i1++)
    {
        if (indegree[i1]==0)
        {
            q1.push(i1) ; asnwer[i1] = 1;
        }
    }

    while (!q1.empty())
    {
        int cur = q1.front()     ;
        q1.pop() ;

        for (int adj : graph[cur] )
        {
            indegree[adj]-- ;
            if (indegree[adj]==0)  
            {
                asnwer[adj] = asnwer[cur]+1;q1.push(adj);
            }
        }
    }
    return asnwer;
}






int main(int argc, char const *argv[])
{
    int n ,m ;
    n=10  ;m =13 ;   //n nodes m edges
    vector<int>graph[n];
    vector<int>indegree(n,0)  ;
    addEdge(0,2,graph,indegree) ;

    addEdge(0,3,graph,indegree) ;
    addEdge(0,4,graph,indegree) ;
    addEdge(1,2,graph,indegree) ;
    addEdge(1,7,graph,indegree) ;
    addEdge(1,8,graph,indegree) ;
    addEdge(2,5,graph,indegree) ;
    addEdge(3,5,graph,indegree) ;
    addEdge(3,7,graph,indegree) ;
    addEdge(4,7,graph,indegree) ;
    addEdge(5,6,graph,indegree) ;
    addEdge(6,7,graph,indegree) ;
    addEdge(7,9,graph,indegree) ;





    return 0;
}

