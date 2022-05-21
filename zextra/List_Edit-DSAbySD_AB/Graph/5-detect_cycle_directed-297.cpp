
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


class Graph1
{
    
public:

    int V ;
    list<int> *grap_var ;
    bool iscycle_util(int v , vector<bool> &visited , vector<bool> &recursive_stack);
    Graph1(int V);
    void addEdge(int u , int v) ;
    bool isCyclic();
};

Graph1::Graph1(int V)
{
    this->V = V ;
    grap_var = new list<int>[V];
}
void Graph1::addEdge(int u, int v)
{
    this->grap_var[u].push_back(v);
}
bool Graph1::iscycle_util(int src , vector<bool> &visited , vector<bool> &recursive_stack)
{
    if(!visited[src])
    {
        visited[src] = true ;
        recursive_stack[src] = true ;

        for (auto neig : this->grap_var[src])
        {
            if(!visited[neig] && iscycle_util(neig,visited,recursive_stack) )
                return true ;
            else if(recursive_stack[neig])
                return true ;
        }
        
        recursive_stack[src] = false ;
    }
    return false ;
}
bool Graph1::isCyclic()
{
    vector<bool>visited(this->V , false);
    vector<bool>rec_stack(this->V , false);
    for (int i1 = 0; i1 < this->V; i1++)
        if(!visited[i1] && iscycle_util(i1,visited,rec_stack) )    
            return true ;

    return false ;
}










