// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1




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

int dfs_util(int i1 ,int j1, int n , int m , vector<vector<int>> &copy_grid )
{
    if(i1<0||j1<0||i1>=n||j1>=m||copy_grid[i1][j1]==0)
        return 0;
    copy_grid[i1][j1] = 0 ;
    int count1 = dfs_util(i1+1,j1,n,m,copy_grid )+dfs_util(i1-1,j1,n,m,copy_grid )+dfs_util(i1,j1+1,n,m,copy_grid )+dfs_util(i1,j1-1,n,m,copy_grid );
    return 1+count1;

}
bool match_dfs(int i1,int j1,int a1 , int b1 ,int n,int m,vector<vector<int>>&grid  )
{
    if(i1<0||j1<0||i1>=n||j1>=m)
    {
        if(a1<0||b1<0||a1>=n||b1>=m)
            return true ;
        else 
            return grid[a1][b1]==0;
    }
    if(a1<0||b1<0||a1>=n||b1>=m)
        return grid[i1][j1]==0;
    

    if(grid[i1][j1]!=grid[a1][b1] )
        return false;
    if(grid[i1][j1]==0 )
        return true ;
    grid[i1][j1] = 0 ;
    grid[a1][b1] = 0 ;
    bool variable = match_dfs(i1+1,j1,a1+1,b1 ,n,m,grid )&&  match_dfs(i1-1,j1,a1-1,b1 ,n,m,grid ) && match_dfs(i1,j1+1,a1,b1+1 ,n,m,grid )&&  match_dfs(i1,j1-1,a1,b1-1 ,n,m,grid );
    grid[i1][j1] = 1 ;
    grid[a1][b1] = 1 ;
    return variable ;
}
int countDistinctIslands(vector<vector<int>>& grid) 
{
    // code here
    int result1 = 0 ;

    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> copy_grid(n,vector<int>(m,0));
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            copy_grid[i1][j1] = grid[i1][j1];

    unordered_map<int,set<pair<int,int>>> map1 ; //number of 1s to coordinates

    int count1 = 0 ;
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(copy_grid[i1][j1]==1)
                count1 = dfs_util(i1,j1,n,m,copy_grid ) , map1[count1].insert({i1,j1});

        
    
    for (auto &keys : map1)
    {
        vector<pair<int,int>>a1(keys.second.begin(),keys.second.end());
        int n1 = a1.size();
        vector<bool> visisted(n1,true);
        for (int i1 = 0; i1 <n1-1 ; i1++)
            for (int j1 = i1+1; j1 < n1; j1++)
                if(visisted[i1])
                    if(match_dfs(a1[i1].first,a1[i1].second ,a1[j1].first ,a1[j1].second ,n,m,grid  ))
                        visisted[i1] = false ;

        for (int i1 = 0; i1 < n1; i1++)
            if(visisted[i1])
                result1++;

    }
    return result1 ;
}








int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    
    int testcase ;
    // long long int n ;//, target;
    // testcase=1 ;
    cin>>testcase;
    while (testcase--)
    {
        int n,m ;
        cin>>n>>m;
        vector<vector<int>>in1(n,vector<int>(m,0));
        // vector<vector<int>>in2(n,vector<int>(m,0));

        for (int i1 = 0; i1 < n; i1++)
            for (int j1 = 0; j1 < m; j1++)
                cin>>in1[i1][j1] ;
                // in2[i1][j1] = in1[i1][j1] ;

        cout<<match_dfs(0,0,2,3,n,m,in1)<<endl;
        // for (int i1 = 0; i1 < n; i1++)
        //     for (int j1 = 0; j1 < m; j1++)
        //     if(in1[i1][j1]==1)
        //         cout<<dfs_util( i1 , j1,  n ,  m , in1 )<<endl;

        // cout<<endl<<"Deug "<< countDistinctIslands(in2)<<endl ;
        // cout<<endl<<"Deug "<<endl ;

    }
    return 0 ;
}




