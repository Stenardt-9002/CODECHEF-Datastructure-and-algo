// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1


#include<bits/stdc++.h>
using namespace std;

      //try wiothut creating visted matrix and use the matrix itself 
    void dfs_util(int srcx ,int srcy,int n,int m , vector<vector<char>> &grid,vector<vector<bool>> &visted)
    {
        if(srcx<0||srcy<0||srcx>=n||srcy>=m||grid[srcx][srcy]=='0'|| visted[srcx][srcy]){return ;}
        visted[srcx][srcy] = true ;
        dfs_util(srcx+1,srcy+1,n,m,grid,visted);
        dfs_util(srcx+1,srcy,n,m,grid,visted);
        dfs_util(srcx+1,srcy-1,n,m,grid,visted);
        dfs_util(srcx-1,srcy+1,n,m,grid,visted);
        dfs_util(srcx-1,srcy,n,m,grid,visted);
        dfs_util(srcx-1,srcy-1,n,m,grid,visted);
        dfs_util(srcx,srcy+1,n,m,grid,visted);
        dfs_util(srcx,srcy-1,n,m,grid,visted);
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size() ; int m = grid[0].size() ;
        int componenets = 0;
        vector<vector<bool>> visted(n) ;
        for(int i1 = 0;i1<n;++i1){visted[i1] = vector<bool>(m,false) ;}
        // when component counted mark value as 0 
        for(int i1 = 0;i1<n;++i1)
        {
            for(int j1 = 0 ;j1<m;++j1)
            {
                if(grid[i1][j1]=='1'&& !visted[i1][j1])
                {
                    dfs_util(i1,j1,n,m,grid,visted) ;
                    componenets++;
                }
            }
        }
        return componenets ;
    }
    