

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



void dfs_util(int x, int y, int n , int m , vector<vector<int>>& matrix,bool &floag)
{
    if(x<0||x>=n||y<0||y>=m )
        return ;

    if((x==0||x==n-1||y==0||y==m-1)&&matrix[x][y]==1 )
        floag=true;


    if(matrix[x][y]==0)
        return ;

    matrix[x][y]=0;

    dfs_util(x+1,y,n,m,matrix,floag);
    dfs_util(x-1,y,n,m,matrix,floag);
    dfs_util(x,y+1,n,m,matrix,floag);
    dfs_util(x,y-1,n,m,matrix,floag);
    
}




int closedIslands(vector<vector<int>>& matrix, int N, int M) 
{
    // Code here

    bool floag=false ;
    int cunt_comp = 0;
    for (int i1 = 0; i1 < N; i1++)
        for (int j1 = 0; j1 < M; j1++)
            if(matrix[i1][j1]==1)    
                {
                    floag = false ;
                    dfs_util(i1,j1,N,M,matrix,floag);
                    if(!floag)
                    cunt_comp++;
                }

    return cunt_comp ;


}


