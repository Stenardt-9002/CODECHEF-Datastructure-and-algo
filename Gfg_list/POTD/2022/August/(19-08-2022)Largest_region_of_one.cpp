// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1













#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool allow_pos(int srcx , int srcy , int N, int M)
{
    return (srcx>=0 && srcy>=0 && srcx<N && srcy<M);
}

int bfs_util(int srcx , int srcy , vector<vector<bool>> &visisted,vector<vector<int>> grid,int n , int m)
{
    int pathx[] = {-1,-1,-1,0,0,1,1,1};
    int pathy[] = {-1,0,1,-1,1,-1,0,1};

    int num_ofones = 0 ;
    visisted[srcx][srcy] = true ;
    queue<pair<int,int>> q1 ; 
    q1.push({srcx,srcy});
    while(!q1.empty())
    {
        pair<int,int> front1 = q1.front();
        q1.pop();
        // visisted[front1.first][front1.second] = true ;
        num_ofones++ ;

        for (int pos = 0; pos < 8; pos++)
        {
            int mewx = front1.first+pathx[pos];
            int mewy = front1.second+pathy[pos];
            if(allow_pos(mewx , mewy , n , m ) && !visisted[mewx][mewy] && grid[mewx][mewy]==1)
            {
                visisted[mewx][mewy] = true ;
                q1.push({mewx,mewy});
            }
        }
        
    }
    return num_ofones ;


}
int findMaxArea(vector<vector<int>>& grid) 
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visisted(n,vector<bool>(m,false));

    int ans1 = 0; 
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            if(!visisted[i1][j1] && grid[i1][j1]==1)
                ans1 = max(bfs_util(i1,j1, visisted,grid ,n,m),ans1);
        
    
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



