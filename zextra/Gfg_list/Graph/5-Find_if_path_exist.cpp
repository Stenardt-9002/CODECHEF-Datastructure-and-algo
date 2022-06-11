// https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1/?page=1&curated[]=5&sortBy=submissions
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


bool isdate(int x ,int y, int n)
{
    return (x>=0&&y>=0&&x<n&&y<n);
}


bool is_Possible(vector<vector<int>>& grid) 
{
    //code here

    int n = grid.size();
    vector<vector<bool>>visisted(n,vector<bool>(n,false));

    int starx = -1,stary=-1;
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < n; j1++)
            if(grid[i1][j1]==1)    
                starx = i1,stary = j1;

    queue<pair<int,int>>q1;
    q1.push({starx,stary});

    visisted[starx][stary] = true ;
    bool flag = true;
    while(!q1.empty()&& flag)
    {
        pair<int,int>top = q1.front();
        starx = top.first ;
        stary = top.second ;
        q1.pop();
        if(grid[starx][stary]==2)
        {
            flag = false ;
            break ;
        }
        if(isdate(starx+1,stary,n) && (grid[starx+1][stary]==3||grid[starx+1][stary]==2) && !visisted[starx+1][stary] )
        {
            visisted[starx+1][stary]=true ;
            q1.push({starx+1,stary});
        }
        if(isdate(starx-1,stary,n) && (grid[starx-1][stary]==3||grid[starx-1][stary]==2) && !visisted[starx-1][stary] )
        {
            visisted[starx-1][stary]=true ;
            q1.push({starx-1,stary});
        }

        if(isdate(starx,stary+1,n) && (grid[starx][stary+1]==3||grid[starx][stary+1]==2) && !visisted[starx][stary+1] )
        {
            visisted[starx][stary+1]=true ;
            q1.push({starx,stary+1});
        }
        if(isdate(starx,stary-1,n) && (grid[starx][stary-1]==3||grid[starx][stary-1]==2) && !visisted[starx][stary-1] )
        {
            visisted[starx][stary-1]=true ;
            q1.push({starx,stary-1});
        }
    }

    if(!flag)
        return true ;

    return false ;

}


