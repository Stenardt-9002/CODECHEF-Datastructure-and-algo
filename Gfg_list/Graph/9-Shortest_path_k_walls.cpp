

// https://practice.geeksforgeeks.org/problems/shortest-path-by-removing-k-walls/1/?page=1&curated[]=5&sortBy=submissions
// https://www.tutorialspoint.com/shortest-path-in-a-grid-with-obstacles-elimination-in-cplusplus
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


void dfs_util(int x , int y, int n , int m , int curk ,int current_cunt,bool &found ,int &ans1,vector<vector<int>> mat,vector<vector<bool>>&visisted)
{
    if(x<0||x>=n||y<0||y>=m )
        return ;
    // cout<<"\nBRUK"<<mat[x][y];
    if(visisted[x][y])
        return ;

    visisted[x][y] = true ;
    if(mat[x][y]==1)
    {
        curk--;
        if(curk<0)
            return ;
    }

    if(x==n-1 &&y==m-1)
    {
        found=true;
        ans1 = min(ans1,current_cunt) ;
        // return ;
    }
    dfs_util(x+1,y,n,m,curk,current_cunt+1,found,ans1,mat,visisted);
    dfs_util(x-1,y,n,m,curk,current_cunt+1,found,ans1,mat,visisted);

    dfs_util(x,y+1,n,m,curk,current_cunt+1,found,ans1,mat,visisted);
    dfs_util(x,y-1,n,m,curk,current_cunt+1,found,ans1,mat,visisted);

    visisted[x][y] = false ;

}

int shotestPath(vector<vector<int>> mat,vector<vector<bool>>visisted, int n, int m, int k) 
{
    // code here
    bool found_ans1=false ;
    int val = INT_MAX ,current_cunt = 0;
    // cout<<"BRUH\n";
    dfs_util(0,0,n,m,k, current_cunt, found_ans1,val,mat,visisted);

    if(found_ans1)
        return val ;

    return -1;
}

int main(int argc, char const *argv[])
{
    int n,m,k ;
    cin>>n>>m>>k ;
    vector<vector<int>>dp1(n,vector<int>(m,0))    ;
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            cin>>dp1[i1][j1];
    
    vector<vector<bool>>visisted(n,vector<bool>(m,false))    ;
    

    // cout<<endl;
    // for (int i1 = 0; i1 < n; i1++)
    //     for (int j1 = 0; j1 < m; j1++)
    //         cout<<dp1[i1][j1]<<" ";


    cout<<shotestPath(dp1,visisted,n,m,k);

    return 0;
}
