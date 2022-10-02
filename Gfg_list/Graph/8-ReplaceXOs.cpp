
// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1/?page=1&curated[]=5&sortBy=submissions


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



void dfs_util(vector<vector<char>> &mat,int sx,int sy , char oldsymbol , char newsmbol,int n , int m)
{
    if(sx<0||sx>=n||sy<0||sy>=m )
        return ;
    
    if(mat[sx][sy]!=oldsymbol)
        return ;

    mat[sx][sy]=newsmbol ;

    dfs_util(mat,sx+1,sy,oldsymbol,newsmbol,n,m);
    dfs_util(mat,sx-1,sy,oldsymbol,newsmbol,n,m);
    dfs_util(mat,sx,sy+1,oldsymbol,newsmbol,n,m);
    dfs_util(mat,sx,sy-1,oldsymbol,newsmbol,n,m);

}


vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // code here
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(mat[i1][j1]=='O')
                mat[i1][j1] = '.';


    //all edges . connected to O
    for (int i1 = 0; i1 < n; i1++)
        if(mat[i1][0]=='.')
            dfs_util(mat,i1,0,'.','O',n,m);
    

    for (int i1 = 0; i1 < n; i1++)
        if(mat[i1][m-1]=='.')
            dfs_util(mat,i1,m-1,'.','O',n,m);
    
    for (int i1 = 0; i1 < m; i1++)
        if(mat[0][i1]=='.')
            dfs_util(mat,0,i1,'.','O',n,m);
    
    for (int i1 = 0; i1 < m; i1++)
        if(mat[n-1][i1]=='.')
            dfs_util(mat,n-1,i1,'.','O',n,m);
    


    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(mat[i1][j1]=='.')    
                mat[i1][j1]='X';

    return mat ;
}



