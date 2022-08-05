    // https://practice.geeksforgeeks.org/problems/x-total-shapes3617/1
    



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void recursive_uitl(vector<vector<char>> &grid , int i1 , int j1 , vector<vector<bool>> &dp1)
{
    if(grid[i1][j1]!='X')
        return ; 
    
    if(dp1[i1][j1])
        return ;
    
    dp1[i1][j1] = true ; 
    if(i1>0)
        recursive_uitl(grid , i1-1 , j1 , dp1) ;

    if(i1<grid.size()-1)
        recursive_uitl(grid , i1+1 , j1 , dp1) ;

    if(j1>0)
        recursive_uitl(grid , i1 , j1-1 , dp1);

    if(j1<grid[0].size()-1)
        recursive_uitl(grid , i1 , j1+1 , dp1) ;

}

int xShape(vector<vector<char>>& grid) 
{
    // Code here
    int ans1 = 0 ;
    int n = grid.size() ; 
    int m = grid[0].size(); 
    vector<vector<bool>> dp1(n,vector<bool>(m,false));
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(grid[i1][j1]=='X' && !dp1[i1][j1])
            {
                ans1++ ;
                recursive_uitl(grid , i1 , j1 ,dp1);
            }


    return ans1 ;


}