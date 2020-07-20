// #undirected graph
#include<iostream>
#include<vector>


using namespace std;

bool cyclerequirefunc(int currentvtix ,bool visited[],int parent,vector <int> g[])
{
    //now here 
    visited[currentvtix] = true;

    for (auto i = g[currentvtix].begin(); i < g[currentvtix].end(); i++)
    {
        //visit each vertice within each vertice recursion
        if (!visited[*i]) //if not visited go with shit
        {
            if (cyclerequirefunc(*i,visited,currentvtix,g))
            {
                return true;
            }
                        
        }

        //if not visited but it is not parent
        //no
        else if(*i != parent)
        {
            return true;
        }

    }
    return false;
}

bool isCyclic(vector<int> g[] , int V)
{
    bool *visited = new bool[V];
    for (int i1 = 0; i1 < V; i1++)
    {
        visited[i1] = false;
    }
    
    for (int u1 = 0; u1 < V; u1++)
    {
        if (!visited[u1])
        {
            if (cyclerequirefunc(u1,visited,-1,g))
            {
                return true ; //found shit
            }
        }
        
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int testcaes ;
    cin>> testcaes;
    while (testcaes--)
    {
        int V,E;
        cin>>V>>E;
        vector<int>adj[V];
        int u,v; 
        for (int i1 = 0; i1 < E; i1++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
    

        }

        cout<<isCyclic(adj,V)<<endl;

    }

    return 0;
}
