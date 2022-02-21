// ??DFS 

#include<bits/stdc++.h>
using namespace std;


bool Cyle_Util(int v , bool *visted , bool *rectack,vector<int> adj[])
{
    if (!visted[v])
    {
        visted[v] = rectack[v] = true ;//add them to visted as well as recursion stack
        vector<int>::iterator i1 ;

        for ( i1 = adj[v].begin(); i1!=adj[v].end(); i1++)
        {
            if (rectack[*i1])
            {
                // cout<<"DEBEGU1 "<<v<<" "<<*i1 <<endl;

                return true ;
            }
            // or already in recursive stack 
            
            else if (!visted[*i1] && Cyle_Util(*i1,visted,rectack,adj) )
            {
                return true ;
            }
            
        }
    }
    rectack[v] = false ; // done remove from recursion stack
    // cout<<"DEBEGU1"<<v<<endl;
    // we didnt find cycle for it 
    return false ;


}


bool isCyclic(int V, vector<int> adj[]) 
    {
         bool *visited = new bool[V]       ;
         bool *recstack = new bool[V];
         for (int i1 = 0; i1 < V; i1++)
         {
            recstack[i1]=visited[i1] = false; 
         }
        
        for (int i1 = 0; i1 < V; i1++)
        {
            if (Cyle_Util(i1,visited,recstack,adj))
            {
                return true ;
            }
            
        }
        return false ;
    }


int main(int argc, char const *argv[])
{

    int V;cin>>V ;
    vector<int> adj[V];
    // for (int i1 = 0; i1 < V; i1++)
    // {
        
    // }
    // adj[0].push_back(1);adj[0].push_back(2);
    // adj[1].push_back(2);
    // adj[2].push_back(0);adj[2].push_back(3);
    // adj[3].push_back(3);




    adj[1].push_back(2);adj[2].push_back(1);
    adj[2].push_back(3);adj[3].push_back(2);
    cout<<isCyclic(4,adj);
    return 0;
}






