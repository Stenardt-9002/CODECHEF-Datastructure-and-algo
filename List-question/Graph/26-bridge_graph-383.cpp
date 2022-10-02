


#include <bits/stdc++.h>
using namespace std;





//disc : discovery time 
// parent : parent bruh 
// low : lowest time 

void bridge_Util(int src , int &time , vector<bool> &viisted ,vector<int> &disc , vector<int> &low,vector<int> &parent , vector<int> adj1[],vector<pair<int,int>> &asn1 )
{
    viisted[src] = true ;
    disc[src] = low[src] = ++time ;
    int des ;
    for (auto i1 = adj1[src].begin(); i1!=adj1[src].end(); i1++)
    {
        des = *i1 ;
//neighbours
        if (!viisted[des])
        {
            parent[des] = src ;
            bridge_Util(des,time ,viisted,disc,low,parent,adj1,asn1);
            low[src] = min(low[src],low[des]);

            if (low[des]>disc[src])
            {
                asn1.push_back({src,des}) ;//edge added
            }
        }
        else if (des!=parent[src])
        {
            //when DFS completed
            low[src] = min(low[src],disc[des]);// take lowest time of path and update it 
        }
    }
}



void addEdge(vector<int> adj[],int u , int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(int argc, char const *argv[])
{

    int V;
    // cin>>V ;
    V = 5;


    vector<bool> visited(V,false);
    vector<int> disc(V);
    vector<int> low(V);
    vector<int> parent(V,0);




    vector<pair<int,int>> asn1 ;



    vector<int> adj1[V];
    addEdge(adj1,1,0);
    addEdge(adj1,0,2);
    addEdge(adj1,2,1);
    addEdge(adj1,0,3);
    addEdge(adj1,3,4);
    
    int time = 0;

    for (int i1 = 0; i1 < V; i1++)
        if (!visited[i1])
            bridge_Util(i1,time,visited,disc,low,parent,adj1,asn1);

    return 0;
}





