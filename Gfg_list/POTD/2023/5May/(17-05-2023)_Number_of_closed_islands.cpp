// https://practice.geeksforgeeks.org/problems/find-number-of-closed-islands/1







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






void dfs_u(int i ,int j ,int N,int M , vector<vector<int>>&matrix)
{
    if(i<0 ||j<0||i>=N||j>=M||matrix[i][j]==0)
        return ;
    matrix[i][j]=0 ;
    dfs_u(i+1 ,j,N,M,matrix);
    dfs_u(i ,j-1,N,M,matrix);
    dfs_u(i ,j+1,N,M,matrix);
    dfs_u(i-1 ,j,N,M,matrix);
    return ;
}

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) 
    {
        // Code here
        int ans = 0 ;
        for(int i = 0 ; i<N;i++)
            for(int j = 0 ; j<M ; j++)
                if((i==0||j==0||i==N-1||j==M-1)&&(matrix[i][j]==1))
                dfs_u(i , j , N,M , matrix);
        for(int i = 0 ; i<N;i++)
            for(int j = 0 ; j<M ; j++)
                if(matrix[i][j]==1)
                    dfs_u(i , j , N,M , matrix) ,ans++;
        
        return ans ;
    }
};