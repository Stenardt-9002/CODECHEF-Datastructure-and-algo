// https://practice.geeksforgeeks.org/problems/hamiltonian-path2522/1




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;

bool dfs_util_hamiltonian(int src , vector<bool>&visited , vector<int> *graph1 , int count_visit)
{
    // cout<<"\nDeug "<<src<<" "<<count_visit ;

    if(count_visit==1 )
        return true ;
    
    visited[src] = true ;

    for(auto child : graph1[src])
        if( !visited[child] && (dfs_util_hamiltonian( child , visited , graph1 , count_visit-1)))
            return true ;
        // if( (count_visit==1 && child==orignalsrc) || (dfs_util_hamiltonian(orignalsrc , child , visited , graph1 , count_visit-1)))
        //     return true ;

    visited[src] = false ;
    return false ;
}



bool check(int N,int M,vector<vector<int>> Edges)
{
    // code here
    vector<int> *graph1 = new vector<int>[N];
    for (int i1 = 0; i1 < M; i1++)
    {
        graph1[Edges[i1][0]-1].push_back(Edges[i1][1]-1);
        graph1[Edges[i1][1]-1].push_back(Edges[i1][0]-1);
    }
    vector<bool> visited(N,false);
    int count_visited = N ;
    for (int src = 0; src < N; src++)
        if(dfs_util_hamiltonian(src ,visited , graph1,count_visited  ))
            return true ;
    return false ;
}



int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        int n , m;
        cin>>n>>m ;
        vector<vector<int>>Edges;
        int start,end ;
        for (int i1 = 0; i1 < m; i1++)
        {
            cin>>start>>end ;
            Edges.push_back({start,end});
        }
        cout<<check(n,m,Edges)<<endl;
    }
    

    return 0;
}









