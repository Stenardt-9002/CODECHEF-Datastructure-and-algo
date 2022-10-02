
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/

#include<bits/stdc++.h>
using namespace std;


// Prims same as dijkstra
int minDis(vector<int> distance , vector<bool> visted,int V)
{
    int min_val = INT_MAX,min_indx =-1;
    for (int i1 = 0; i1 < V; i1++)
    {
        //if not visited 
        if (!visted[i1] && distance[i1]<min_val )
        {
            min_val = distance[i1] ; min_indx = i1 ;
        }
        //for not visited and are at minium distance 
    }
    
    return min_indx ;

}

//primMST
int spanningTree(int V, vector<vector<int>> adj[])
{

    vector<int> parent(V);
    vector<int> dis1t(V,INT_MAX);
    vector<bool> visited1(V,false) ;


    dis1t[0]=0; //src distance is 0 
    parent[0] = -1;

//same as dijkstra 
    int src ,des ;
    int asn1 = 0 ;
    for (int count1 = 0; count1 < V-1; count1++)
    {
        //V-1 same as dijkstra 
        // get node which has minimum distance 
        src = minDis(dis1t,visited1,V);


        //include src in visted 
        visited1[src] = true ;


    //src-> {dest and weight}

        // and update it neighbours 
        for (auto i:adj[src])
        {
            // its is not visted 
            if (!visited1[i[0]] && dis1t[i[0]]>i[1] )
            {
                parent[i[0]] = src ;
                dis1t[i[0]] = i[1] ;
            }
        }
    }
    
    // asn1 = *
    for (int i1 = 0; i1 < V; i1++)
    {
        asn1+=dis1t[i1] ;
    }
    
    return asn1 ;
}





int main(int argc, char const *argv[])
{



    return 0;
}






