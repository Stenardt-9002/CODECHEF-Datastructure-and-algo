
// https://practice.geeksforgeeks.org/problems/7366ce450d84b55391fc787a681c4d60de359e72/1












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





















class Solution {
  public:
    // static int dir[] = {0,-1,0,1,0};
    int shortestXYDist(vector<vector<char>> grid, int N, int M) 
    {
        // code here
        static int dir[] = {0,-1,0,1,0};
        queue<pair<int,int>> q1 ;
        if(N==1 && M==1)
            return 0 ;
        
        for(int i = 0 ; i<N;i++)
            for(int j = 0 ; j<M; j++)
                if(grid[i][j]=='X')
                    q1.push({i,j});
        
        int ans = 0 ;
        while(q1.size())
        {
            int n = q1.size();
            ans++ ;
            while(n--)
            {
                pair<int,int> front = q1.front();
                q1.pop();
                for(int d = 0 ; d<4;d++)
                {
                    int newx = front.first+dir[d];
                    int newy = front.second+dir[d+1];
                    if(newx>=0 && newy>=0 && newx<N && newy<M && grid[newx][newy]!='X')
                    {
                        if(grid[newx][newy]=='Y')
                            return ans ;
                        q1.push({newx , newy});
                        grid[newx][newy] = 'X';
                    }
                }
            }
        }
        return -1 ;
        
    }
};