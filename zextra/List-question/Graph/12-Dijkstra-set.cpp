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

    set<pair<int,int>> heap1 ;
    vector<int> dis1t(V,INT_MAX) ;

    heap1.insert({0,src});

    dis1t[src] = 0;
    int u , v, weigjt ;
    while (!heap1.empty())
    {
        pair<int,int> temp = *(heap1.begin()) ;
        heap1.erase(heap1.begin()) ;
        u = temp.second ;

        for (auto i1 = adj1[u].begin(); i1!=adj1[u].end(); i1++)
        {
            //update the neighbours 
            v = (*i1).first ;
            weigjt = (*i1).second ;

            if (dis1t[v]>dis1t[u]+weigjt)
            {
                if (dis1t[v]!=INT_MAX)
                {
                    heap1.erase(heap1.find({dis1t[v],v}));
                }
                dis1t[v]=dis1t[u]+weigjt;
                heap1.insert({dis1t[v],v});
            }
        }
    }
    return dis1t ;
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






