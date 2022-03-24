
// 

// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

#include <bits/stdc++.h>

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;

struct data1
{
    int x, y ,  data ;
};


bool isavalid(int x,int y,int m ,int n)
{
    return (x<n &&x>=0&&y<m&&y>=0);
}



// int get_distance(int i1,int j1,int n , int m ,vector<vector<int>>grid1)
// {
//     queue<data1> q1 ;
//     int disance = 0;
//     data1 var1 ;
//     var1.x = i1 ;
//     var1.y = j1 ;
//     var1.data = disance ;
//     q1.push(var1);
//     while (!q1.empty())
//     {
//         var1 = q1.front() ;
//         disance = var1.data+1 ;
//         q1.pop() ;
//         int datax[] = {-1,-1,-1,0,0,0,1,1,1};
//         int datay[] = {-1,0,1,-1,0,1,-1,0,1};

//         for (int a = 0; a < 8; a++)
//         {
//             if(isavalid(var1.x+datax[a],var1.y+datay[a],m,n) && grid1[var1.x+datax[a]][var1.y+datay[a]]==1 )
//                 return disance ; 
//             else if(isavalid(var1.x+datax[a],var1.y+datay[a],m,n) && grid1[var1.x+datax[a]][var1.y+datay[a]]==0 )
//             {
//                 data1 t1 ;
//                 t1.data = disance ;
//                 t1.x = var1.x+datax[a];t1.y = var1.y+datay[a];
//                 q1.push(t1);
//             }
//         }
//     }
//     return INT_MAX ;    
// }


// 	vector<vector<int>>nearest(vector<vector<int>>grid)
// 	{
// 	    // Code here
//         int n = grid.size() ;
//         int m ;
//         queue<data1> q1 ;
//         vector<vector<int>> a1 ;
//         for (int i1 = 0; i1 < n; i1++)
//         {
//             vector<int>temp1;
//             m = grid[i1].size() ;
//             for (int j1 = 0; j1 < m; j1++)
//             {
                
//                 int distance = 0 ;
//                 if (grid[i1][j1]==0)
//                     distance = get_distance(i1,j1,n,m,grid);
//                 else
//                     distance = 0 ;                                 

//                 temp1.push_back(distance) ;
//             }
//             a1.push_back(temp1) ;
//         }
//         return a1 ;
        
// 	}


void creategraph(vector<vector<int>> grid,vector<int>graph1[] )
{
    int n = grid.size() ; 
    int m = grid[0].size() ;  
    // vector<int>graph1[(n+1)*(m+1)];
    // vector<int>graph1[5000];



    int node1 = 0 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            if (i1==n-1)
            {
                if(j1!=m-1)
                {
                    graph1[node1].push_back(node1+1) ;
                    graph1[node1+1].push_back(node1) ;
                }
                
            }
            else if(j1==m-1)
            {
                graph1[node1].push_back(node1+m) ;
                graph1[node1+m].push_back(node1) ;
            }
            else 
            {
                    graph1[node1].push_back(node1+1) ;
                    graph1[node1+1].push_back(node1) ;
                    graph1[node1].push_back(node1+m) ;
                    graph1[node1+m].push_back(node1) ;
            }
            node1++ ;
        }
    }
    // cout<<node1<<endl;
    // n*m modes 
}




	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> ans123 ; 
        vector<int> *gra1 = new vector<int>[(m+1)*(n+1)];
         creategraph(grid,gra1 ) ; 

        vector<int> disance1(m*n,INT_MAX) ; 
        vector<bool> visited1(m*n,false) ;
       
        for (int i1 = 0; i1 < n*m; i1++)
        {
            cout<<endl ;
            for (int j1 = 0 ; j1<gra1[i1].size();j1++)
                cout<<" "<<gra1[i1][j1] ; 
            
        }
        

        queue<int> q1 ; 
        int nod = 0 ;
        for (int i1 = 0; i1 < n; i1++)
        {
            for (int k1 = 0; k1 < m; k1++)
            {
                if (grid[i1][k1]==1)
                {
                    disance1[nod] = 0 ;
                    visited1[nod] = true ;
                    q1.push(nod) ;
                }
                nod++ ;
            }
        }
        
        //bfs 
        int tem  ;
        while (!q1.empty())
        {
            tem = q1.front() ;
            q1.pop() ;

            for (auto neigj : gra1[tem])
            {
                if (!visited1[neigj])
                {
                    disance1[neigj] = min(disance1[neigj] , disance1[tem]+1) ;
                    q1.push(neigj) ;
                    visited1[neigj] = true;
                }
            }
        }
        tem= 0 ;
        for (int i1 = 0; i1 < n; i1++)
        {
            vector<int>t3mp1;
            for (int j1 = 0; j1 < m; j1++)
            {
                t3mp1.push_back(disance1[tem]);
                tem++;
            }
            ans123.push_back(t3mp1) ;
        }
        return ans123 ;
        
	}



int main(int argc, char const *argv[])
{



    int n,m;cin>>n>>m ;
    vector<vector<int>> ar1 ; 

    for (int i1 = 0; i1 < n; i1++)
    {
        vector<int> tem1p(m) ;
        for (int j1 = 0; j1 < m; j1++)
            cin>>tem1p[j1] ;

        ar1.push_back(tem1p)         ;
    }
    
     vector<vector<int>> ae1 = nearest(ar1) ;


    return 0;
}




