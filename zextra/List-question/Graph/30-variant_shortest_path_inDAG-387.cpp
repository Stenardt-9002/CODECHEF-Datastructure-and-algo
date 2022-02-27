

// https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/



#include <bits/stdc++.h>
using namespace std;



void dfs_util(int src , vector<bool> &visited , stack<int> &st,vector<pair<int,int>>adj1[])
{
    visited[src] = true ;
    for (auto i=adj1[src].begin();i!=adj1[src].end();i++ )
        if (!visited[i->first])
            dfs_util(i->first,visited,st,adj1);
            
    st.push(src);
}


void shorest_path(int src , int V , vector<pair<int,int>>adj1[])
{

    stack<int> S1 ;
    vector<bool> vsited(V,false);
    vector<int> dist1(V,INT_MAX);

    for (int i1 = 0; i1 < V; i1++)
        if (!vsited[i1])
            dfs_util(i1,vsited,S1,adj1);



    dist1[src] = 0; // got topological order 
    int u ;
    while (!S1.empty())
    {
        u = S1.top();S1.pop();
        if(dist1[u]!=INT_MAX)
        {
            for (auto i1 = adj1[u].begin(); i1 !=adj1[u].end(); i1++)
            {
                if (dist1[i1->first]>(dist1[u]+i1->second))
                    dist1[i1->first] = dist1[u]+i1->second;
            }
        }    
    }


    


}


void addEge(int u , int v , int weght,vector<pair<int,int>>adj1[])
{
    adj1[u].push_back({v,weght});
}

int main(int argc, char const *argv[])
{
    
    int V ;cin>>V;
    vector<pair<int,int>>adj1[V];
    int E ;cin>>E ;
    int temp1s , temp1d , weight2 ; 
    while (E--)
    {
        cin>>temp1s>>temp1d>>weight2 ;
        addEge(temp1s,temp1d,weight2,adj1);
    }
    
    shorest_path(1,V,adj1);

    return 0;
}






