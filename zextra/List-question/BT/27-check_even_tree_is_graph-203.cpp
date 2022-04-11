#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

void addEdge(vector<int> *edge_list , int u,int v)
{
    edge_list[v].push_back(u) ;
    edge_list[u].push_back(v) ;
}



bool cehck_if_cycle(int u,vector<bool> &visted1,vector<int> *edge_list,int parent=-1)
{
    visted1[u] = true; 
    for (auto v : edge_list[u])
    {
        if(!visted1[v])
        {
            if(cehck_if_cycle(v,visted1,edge_list,u))
                return true;
        }
        //if adjacent is visited and not parent of curent then there is cycle
        else if (v!=parent)
            return true ;
    }
    return false ;
}
 


bool istree(int vertce , vector<int> *edge_list)
{
    vector<bool>visted1(vertce,false);

    if(cehck_if_cycle(0,visted1,edge_list))
        return false ;

    //check if one component 
    for (int u = 0; u < vertce; u++)
        if(!visted1[u])    
            return false ;

    return true ;
}

int main(int argc, char const *argv[])
{

    int vertice ;
    // cin>>vertice ;
    vertice = 5;
    vector<int> *edge_list = new vector<int>[vertice];

    addEdge(edge_list,1,0);
    addEdge(edge_list,2,0);
    addEdge(edge_list,3,0);
    addEdge(edge_list,3,4);

    cout<<endl<<istree(vertice,edge_list);
    delete []edge_list ;



    vertice = 5;
    edge_list = new vector<int>[vertice];


    addEdge(edge_list,1,0);
    addEdge(edge_list,2,0);
    addEdge(edge_list,2,1);
    addEdge(edge_list,3,0);
    addEdge(edge_list,3,4);

    cout<<endl<<istree(vertice,edge_list);
    delete []edge_list ;

    return 0;
}







