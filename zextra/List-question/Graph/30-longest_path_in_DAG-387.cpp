


// https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/


#include <bits/stdc++.h>
using namespace std;

// class Node1
// {
// public:
//     int v ,weight ;

//     Node1(int v , int we)
//     {
//         this->v = v ;this->weight = we ;
//     }
// };



void dfs_util(int src , vector<bool> &visited , stack<int> &st,vector<pair<int,int>>adj1[])
{
    visited[src] = true ;
    vector<pair<int,int>>::iterator i1 ;
    for ( i1 = adj1[src].begin(); i1 != adj1[src].end(); i1++)
        if (!visited[i1->first])
            dfs_util(i1->first,visited,st,adj1);

    st.push(src);
}


void longest_path(int src , int V , vector<pair<int,int>>adj1[])
{
    stack<int> St ;
    vector<bool>visisted(V,false) ;
    vector<int>dist1(V,INT_MIN);

    for (int i1 = 0; i1 < V; i1++)
        if (!visisted[i1])
            dfs_util(i1,visisted,St,adj1);
    
    dist1[src] = 0;
    while (!St.empty())
    {
        int u = St.top() ; St.pop() ;

        vector<pair<int,int>>::iterator i1 ;
        if (dist1[u]!=INT_MIN)
        {
            //visit all neighbours 
            for ( i1 = adj1[u].begin(); i1 !=adj1[u].end(); i1++)
            {
                if (dist1[i1->first]<(dist1[u]+i1->second) )
                {
                    dist1[i1->first] = dist1[u]+i1->second;
                }
            }
        }
    }
    

    for (auto i:dist1)
    {
        if (i==INT_MIN)
            cout<<" INF ";
        else
            cout<<i<<" ";
        
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
    
    longest_path(1,V,adj1);

    return 0;
}








