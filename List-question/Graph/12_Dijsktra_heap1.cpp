
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

#include <bits/stdc++.h>
using namespace std;


void addEdge(int u,int v , int w,vector<pair<int,int>> adj1[])
{
    adj1[u].push_back(make_pair(v,w)) ;
    adj1[v].push_back(make_pair(u,w)) ;
}



vector<int> shortestPath(int src,int V,vector<pair<int,int>> adj1[]) 
{

    priority_queue< pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> > pq;
    vector<int> di1st(V,INT_MAX) ;
    pq.push(make_pair(0,src)) ;
    di1st[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second ; //minimum distance 
        pq.pop();
        for (auto i=adj1[u].begin(); i!=adj1[u].end(); i++)
        {
            //update all neibour of curent vertex
            int v = (*i).first ;
            int weight = (*i).second ;

            if (di1st[v]>di1st[u]+weight)
            {
                di1st[v]=di1st[u]+weight;
                pq.push(make_pair(di1st[v],v));
            }
        }
    }
    return di1st ;
}




int main(int argc, char const *argv[])
{
    int V ;

    vector<pair<int,int>> *adj ;

    addEdge(0,1,4,adj);
    addEdge(0,7,8,adj);
    addEdge(1,2,8,adj);
    addEdge(1,7,11,adj);
    addEdge(2,3,7,adj);
    addEdge(2,8,2,adj);
    addEdge(2,5,4,adj);
    addEdge(3,4,9,adj);
    addEdge(3,5,14,adj);
    addEdge(4,5,10,adj);
    addEdge(5,6,2,adj);
    addEdge(6,7,1,adj);
    addEdge(6,8,6,adj);
    addEdge(7,8,7,adj);












    return 0;
}


