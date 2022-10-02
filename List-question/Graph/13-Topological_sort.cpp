



#include <bits/stdc++.h>
using namespace std;

void dfstopologicalSort(int src, vector<bool> &vsited,vector<int>adj[],vector<int>& answer)
{
    vsited[src] = true ;
    vector<int>::iterator i1 ;

    for ( i1 = adj[src].begin(); i1 !=adj[src].end(); i1++)
    {
        if (!vsited[*i1])
        {
            dfstopologicalSort(*i1,vsited,adj,answer);
        }
        
    }
    answer.push_back(src) ;
}



vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> asn1  ; 
    vector<bool> vsited(V,false );

    for (int i1 = 0; i1 < V; i1++)
    {
        if (!vsited[i1])
        {
            dfstopologicalSort(i1,vsited,adj,asn1);
        }
    }
    reverse(asn1.begin(),asn1.end()) ;
    return asn1 ;
}











int main(int argc, char const *argv[])
{
    
    return 0;
}




