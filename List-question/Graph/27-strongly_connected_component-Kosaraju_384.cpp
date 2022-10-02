
// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/







#include <bits/stdc++.h>
using namespace std;




void DFS1before(int src, vector<bool> &vsited , stack<int> &stac1,vector<int>adj[])
{
    vsited[src] = true ;
    //visit neighbours 
    for (auto i1 = adj[src].begin(); i1!=adj[src].end() ; i1++)
        if (!vsited[*i1])
            DFS1before(*i1,vsited,stac1,adj)            ;

    stac1.push(src);

}




void reverse_graph1(int V,vector<int> adj[] , vector<int> aans[])
{
    for (int src = 0; src < V; src++)
    {
        for (auto des = adj[src].begin() ; des !=adj[src].end(); des++)
        {
            aans[*des].push_back(src);
        }
    }
}





// reverse DFS


void DFS2after(int src, vector<bool> &vsited , vector<int>reverse1[])
{
    vsited[src] = true ;
    // cout<<" "<<src<<" ";
    //visit neighbours 
    for (auto i1 = reverse1[src].begin(); i1!=reverse1[src].end() ; i1++)
        if (!vsited[*i1])
            DFS2after(*i1,vsited,reverse1)            ;
}









int kosaraju(int V, vector<int> adj[])
{
    int asn1 = 0;
    vector<bool> visted1(V,false) ;
    stack<int> stack1 ;

    for (int i1 = 0; i1 < V; i1++)
        if (!visted1[i1])
            DFS1before(i1,visted1,stack1,adj);


    //reverse Graph
    vector<int> reverse1[V];
    reverse_graph1(V,adj,reverse1);

    //init visited 
    for (int i1 = 0; i1 < V; i1++)
        visted1[i1] = false;


    //start again 
    int src ;
    while (!stack1.empty())
    {
        src = stack1.top() ; stack1.pop();

        if (!visted1[src])
        {
            DFS2after(src , visted1 ,reverse1);
            // cout<<endl<<endl;
            asn1++;
        }
        
    }
    
    return asn1;




}

void addedge(int src,int des,vector<int>adj[])
{
    adj[src].push_back(des);
}

int main(int argc, char const *argv[])
{
    int V ;
    // cin>>V ;
    V = 10 ;
    vector<int> adj1[V];

    addedge(0,1,adj1);
    addedge(1,5,adj1);
    addedge(5,0,adj1);
    addedge(0,2,adj1);


    addedge(2,3,adj1);
    addedge(3,4,adj1);
    addedge(4,2,adj1);


    addedge(1,6,adj1);
    addedge(6,7,adj1);
    addedge(7,8,adj1);





    addedge(8,9,adj1);
    addedge(9,7,adj1);



    cout<<kosaraju(V,adj1);

    return 0;
}






