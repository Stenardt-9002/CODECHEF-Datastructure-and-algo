// ??DFS 
#include<bits/stdc++.h>
using namespace std;


bool Cyle_util(int start,vector<bool> &visted ,int paretn,vector<int> adv[])
{
    visted[start] = true ;
    for (auto i1 = adv[start].begin(); i1 !=adv[start].end(); i1++)
    {
        if (!visted[*i1])
        {
            if (Cyle_util(*i1,visted,start,adv)) //vsited is now the new parent
            {
                return true ;
            }
        }
        //if vsited and not previous then means 
        else if(*i1!=paretn)
        {
            return true ;//sinc not parent is already visited therefore loop
        }
    }
    return false ;
}
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool>vsited(V,false );
        for (int strtn = 0; strtn < V; strtn++)
        {
            if (!vsited[strtn])
            {
                if (Cyle_util(strtn,vsited,-1,adj))
                {
                    return true ;
                }
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
    adj[0].push_back(1);adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);adj[2].push_back(3);
    adj[3].push_back(3);


    return 0;
}



