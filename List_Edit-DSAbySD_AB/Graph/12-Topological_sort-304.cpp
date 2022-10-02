//Kahn Algorithm
// https://practice.geeksforgeeks.org/problems/topological-sort/1



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int>degree_in(V,0) ;
    for (int nodes = 0; nodes < V; nodes++)
        for (auto neig: adj[nodes])  
            degree_in[neig]++;

    queue<int> q1 ;
    int i1 ;
    for ( i1 = 0; i1 < V; i1++)
        if(degree_in[i1]==0)    
            q1.push(i1) ;

    int cnt = 0,front1;
    vector<int> ans1 ; 
    while (!q1.empty())
    {
        front1 = q1.front() ;
        q1.pop() ;
        ans1.push_back(front1) ;
        //visit neighbours decrement their indgree by 1 
        for(auto neig : adj[front1])
        {   
            degree_in[neig]-- ;
            if(degree_in[neig]==0)
                q1.push(neig);
        }
        cnt++ ;
    }
    if(cnt!=V)
        return {} ;
    
    
    return ans1 ;

}















