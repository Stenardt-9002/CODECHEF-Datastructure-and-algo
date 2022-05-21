
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
    bool iscycle_util(int v , vector<bool> &visited , int parent=-1);
    Graph1(int V);
    void addEdge(int u , int v) ;
    bool isCyclic();
};

bool Graph1::iscycle_util(int v , vector<bool> &visited , int parent=-1)
{
    visited[v] = true ;
    for (auto neig : grap_var[v])
    {
        if(!visited[neig] && iscycle_util(neig,visited,v))
            return true ;
        //if already visited
        else if(visited[neig] && neig!=parent)
            return true;
    }
    return false;
}
bool Graph1::isCyclic()
{
    vector<bool> vsiited(this->V , false);
    for (int u = 0; u < this->V; u++)
        if(!vsiited[u])    
            if(iscycle_util(u,vsiited,-1))
                return true ;

    return false ;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}




