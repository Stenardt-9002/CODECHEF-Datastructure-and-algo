





#include <bits/stdc++.h>
using namespace std;


            // DFSutil(adj,u,vsited,disc,low,curtime,parent1,isartipoint );


void DFSutil(vector<int> adj[],int src ,vector<bool> &vsited,vector<int> &disc ,vector<int> &low,int &curtime , int parent1,vector<bool>&isartipoint)
{
    int childten = 0;

    vsited[src] = true ;

    //init discovery and low value 
    disc[src] = low[src] = ++curtime ;

    for (auto v : adj[src])
    {
        if (!vsited[v])
        {
            childten++ ;//individual childs
            DFSutil(adj,v,vsited,disc,low,curtime,parent1,isartipoint)            ;

            low[src] = min(low[src],low[v]);

            if (parent1!=-1 && low[v]>=disc[src] )
            {
                isartipoint[src] = true ;
            }
        }
        else if (v!=parent1)
        {
            low[src] = min(low[src],disc[v]);
        }
    }
    // if root gone then children are independent components therefor it is articulation point
    if (parent1==-1 && childten>1 )
    {
        isartipoint[src] = true;
    }
}



void ArticulationPoint(vector<int> adj[],int v,stack<int> &asn1)
{
    //disc , low ,isartipoint 

    //stores discovery time 
    vector<int> disc(v,0);
    //low earliest visited vertex (vertex with min discovery time) that can be reached from subtree
    vector<int> low(v,0);
    vector<bool> vsited(v,false);
    vector<bool> isartipoint(v,false);

    int curtime =0,parent1 = -1 ;

    for (int u = 0; u < v; u++)
    {
        if (!vsited[u])
        {
            DFSutil(adj,u,vsited,disc,low,curtime,parent1,isartipoint );
        }
    }

    for (int u = 0; u < v; u++)
    {
        if (isartipoint[u])
        {
            asn1.push(u);
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
    cin>>V ;
    vector<int> adj1[V];
    addEdge(adj1,1,0);
    addEdge(adj1,0,2);
    addEdge(adj1,2,1);
    addEdge(adj1,0,3);
    addEdge(adj1,3,4);
    



    return 0;
}







