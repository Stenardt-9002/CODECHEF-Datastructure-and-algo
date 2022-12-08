// https://leetcode.com/problems/decode-ways/?envType=study-plan&id=dynamic-programming-i











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


vector<vector<int>>nearest(vector<vector<int>>grid)
{
    // Code here
    static int arrx[] = {0,-1,0,1,0};
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>>q1 ;
    for (int i1 = 0; i1 < n; i1++)
        for (int j = 0; j < m; j++)
            if(grid[i1][j]==1)
            {
                q1.push({i1,j});
                grid[i1][j]=-1 ;
            }

    int cur_dis = 0;
    while (!q1.empty())
    {
        cur_dis++ ;
        int size = q1.size();
        while(size--)
        {
            pair<int,int> p = q1.front();
            q1.pop();
            int curx = p.first ;
            int cury = p.second ;
            for (int i = 0; i < 4; i++)
            {
                int newx = curx+arrx[i];
                int newy = cury+arrx[1+i];
                if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==0)
                {
                    grid[newx][newy]=cur_dis ;
                    q1.push({newx , newy});
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(grid[i][j]==-1)
                grid[i][j] = 0;
    
    return grid ;
}

