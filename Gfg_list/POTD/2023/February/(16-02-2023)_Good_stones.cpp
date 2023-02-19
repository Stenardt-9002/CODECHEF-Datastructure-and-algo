// https://practice.geeksforgeeks.org/problems/e2d156755ca4e0a9b9abf5680191d4b06e52b1a8/1















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










class Solution{
public:
    int cycle_detection(int src ,int n , vector<int>arr ,vector<int>&visited ,vector<int>& dp1  ) 
    {
        if(src>=n || src<0)
            return 1 ;

        if(visited[src]==1)
            return 0 ; 
        
        if(dp1[src]!=-1)
            return dp1[src] ; 

        visited[src]=1 ;
        dp1[src] = cycle_detection(src+arr[src] , n , arr , visited , dp1);
        visited[src]=0 ;
        return dp1[src];
    }

    int goodStones(int n,vector<int> &arr)
    {
        // Code here
        vector<int> dp1(n,-1) , visited(n,0);
        for (int i = 0; i < n; i++)
            if(dp1[i]==-1 )
                dp1[i]=cycle_detection(i ,n , arr , visited , dp1  ) ;
        int ans = 0 ;
        for (int i = 0; i < n; i++)
            ans+=(dp1[i]==1);

        return ans ;        
    }  
};





// class Solution{
// public:
//     int n1 ;
//     vector<int>&visited ;
//     bool cycle_detection(int src , vector<int>arr )
//     {
//         if(src>=n1 || src<0)
//             return 1 ;

//         if(visited[src]!=-1)
//             return visited[src] ;
//         visited[src] = 0 ;
//         return visited[src] = cycle_detection(src+arr[src] , arr ) ;
//     }

//     int goodStones(int n,vector<int> &arr)
//     {
//         // Code here
//         this->n1 = n ;
//         visited.resize(n,-1) ;//, dfs_stack(n,0);
//         for (int i = 0; i < n; i++)
//             if(visited[i]==-1 )
//                 visited[i]=cycle_detection(i ,arr ) ;
//         return accumulate(visited.begin() , visited.end() , 0);
//     }  
// };








