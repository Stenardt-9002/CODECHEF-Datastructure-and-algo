// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1











#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void DFS_uitl(int srcx , int srcy,vector<vector<int>> &grid ,int n , int m , int &current_count)
{
    if(srcx<0 || srcy<0 || srcx>=n || srcy>=m || grid[srcx][srcy]==0)
        return ;
    int pathx[] = {-1,-1,-1,0,0,1,1,1};
    int pathy[] = {-1,0,1,-1,1,-1,0,1};
    current_count++ ;
    grid[srcx][srcy] = 0  ; 
    for (int pos= 0; pos < 8; pos++)
        DFS_uitl(srcx+pathx[pos] , srcy+pathy[pos] , grid,n,m,current_count);
    
}




int findMaxArea(vector<vector<int>>& grid) 
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();

    int ans1 = 0; 
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(grid[i1][j1]==1)
            {
                int curre_ntcount= 0;
                DFS_uitl(i1,j1,grid,n,m,curre_ntcount);
                ans1 = max(ans1,curre_ntcount);
            }
        
    
    return ans1 ;
}



int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    int n ,m;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n>>m;
        vector<vector<int>>grid1(n,vector<int>(m, 0));
        
        for (int i1 = 0; i1 < n; i1++)
            for (int j1 = 0; j1 < m; j1++)
                cin>>grid1[i1][j1];
        
        cout<<findMaxArea(grid1)<<endl ;
    }
    return 0 ;
}






