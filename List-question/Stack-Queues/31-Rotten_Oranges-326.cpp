// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

#include <bits/stdc++.h>
using namespace std;

bool isvalid_loc(int i1,int j1,int n , int m)
 {
    return (i1>=0&&j1>=0&&i1<n&&j1<m);
 }


    int orangesRotting(vector<vector<int>>& grid) 
    {
        
            // Code here
        
        int time1 = 0 ;
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q1 ;
        // vector<vector<int>> store_time(n,vector<int>(m,-1)) ;
        for(int i1 = 0 ;i1<n;i1++)
            {
                for(int j1=0;j1<m;j1++)
                {
                    if(grid[i1][j1]==2)
                    {
                        vector<int> temp1 = {i1,j1,time1};
                        q1.push(temp1) ;
                        // store_time[i1][j1] = 0 ;
                    }
                    // else if(grid[i1][j1]==1)
                    //     store_time[i1][j1] = INT_MAX ;
                }
            }
        int i,j ;
        while(!q1.empty())
        {
            time1 = q1.front()[2];
            j = q1.front()[1];
            i = q1.front()[0];
            q1.pop() ;
            if(isvalid_loc(i,j+1,n,m)&&(grid[i][j+1]==1))
                {
                    // if(store_time[i][j+1]>time1+1)
                    q1.push({i,j+1,time1+1});

                    // store_time[i][j+1] = min(store_time[i][j+1],time1+1);
                    grid[i][j+1] = 2;
                }

            if(isvalid_loc(i,j-1,n,m)&&(grid[i][j-1]==1))
                {
            // if(j-1>=0&&(grid[i][j-1]==1||grid[i][j-1]==2))
                    // if(store_time[i][j-1]>time1+1)
                    q1.push({i,j-1,time1+1});

                    // store_time[i][j-1] = min(store_time[i][j-1],time1+1);
                    grid[i][j-1] = 2 ;
                }
            if(isvalid_loc(i+1,j,n,m)&&(grid[i+1][j]==1))
                {
            // if(i+1<n&&(grid[i+1][j]==1||grid[i+1][j]==2))
                    // if(store_time[i+1][j]>time1+1)
                    q1.push({i+1,j,time1+1});

                    // store_time[i+1][j] = min(store_time[i+1][j],time1+1);
                    grid[i+1][j] = 2 ;
                }
            if(isvalid_loc(i-1,j,n,m)&&(grid[i-1][j]==1))
                {
            // if(i-1>=0&&(grid[i-1][j]==1||grid[i-1][j]==2))
                    // if(store_time[i-1][j]>time1+1)
                    q1.push({i-1,j,time1+1});

                    // store_time[i-1][j] = min(store_time[i+1][j],time1+1);
                    grid[i-1][j] = 2 ;
                }

            

        }
        for (int i1 = 0; i1 < n; i1++)
        {
            // cout<<endl ;
            for (int j1 = 0; j1 < m; j1++)
            {
                // cout<<" "<<store_time[i1][j1];
                if (grid[i1][j1]==1)
                    return -1 ;                
            }    
        }
        
        return time1;
    }


int main(int argc, char const *argv[])
{
    int n,m ;
    cin>>n>>m ;
    vector<vector<int>> grid ;

    for (int i1 = 0; i1 < n; i1++)
    {
        vector<int> ttem1(m,-1);
        for (int j1 = 0; j1 < m; j1++)
            cin>>ttem1[j1] ;
        grid.push_back(ttem1);
    }
    for(auto x: grid)
        {
            cout<<endl ;
            for(auto y:x)
            cout<<" "<<y ;
        }
    // cout<<"REached\n" ;
    cout<<orangesRotting(grid)<<" ";

    return 0;
}






