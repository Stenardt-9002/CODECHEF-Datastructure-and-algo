// https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1







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





int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                    pair<int, int> destination) {
    // code here
        int startx = source.first ;
        int starty = source.second ;
        int dist[] = {0,-1,0,1,0};
    
        if(grid[startx][starty]==0)
            return -1 ;
        if(source.first==destination.first && source.second == destination.second)
            return 0;
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q1 ;
        q1.push({startx ,starty , 0});
        // vector<vector<bool>>visised(n,vector<bool>(m,false));
        while (!q1.empty())
        {
            vector<int> front1 = q1.front()    ;
            q1.pop();
            for (int i1 = 0; i1 < 4; i1++)
            {
                int newx = front1[0]+dist[i1];
                int newy = front1[1]+dist[i1+1];
                if(newx==destination.first && newy == destination.second)
                    return front1[2]+1;
                if(newx>=0 && newy>=0&& newx<n&& newy<m && grid[newx][newy]==1)
                {
                    grid[newx][newy]=0 ;
                    q1.push({newx,newy , front1[2]+1});
                }
            }
        }
        
        return -1 ;
}



// 1 1
// 1
// 0 0
// 0 0
