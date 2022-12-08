// https://practice.geeksforgeeks.org/problems/shortest-path-by-removing-k-walls/1












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



//User function Template for C++

class Solution {
  public:
  
  
  
    static int bfs_util(vector<vector<int>>&matr , int k ,int n , int m)
    {
        vector<vector<int>>visisted(n,vector<int>(m,-1))    ;
        queue<tuple<int,int,int,int>> q1 ; //x , y , current path , k left
    
        q1.push(make_tuple(0,0,0,k));
    
        while(!q1.empty())
        {
            tuple<int,int,int,int> t1 = q1.front();
            int curx = get<0>(t1);
            int cury = get<1>(t1);
            int curd = get<2>(t1);
            int curk = get<3>(t1);
            q1.pop();
            // cout<<"reavcjed";
            if(curx<0||curx>=n||cury<0||cury>=m)
                continue ; //continue with loop
    
            //answer reached 
            if(curx==n-1&&cury==m-1)
                return curd;
    
            if(matr[curx][cury]==1)//wall found
            {
                if(curk<=0)
                    continue ;
                curk-- ;
            }
    
            //NOT VISISTED 
            if(visisted[curx][cury]!=-1 && visisted[curx][cury]>=curk)//if better curk is not possible continue
                continue ;
    
            visisted[curx][cury] = curk ;//vsisted and curk is the better possibilty
    
    
            //queue push 4 direction 
            q1.push(make_tuple(curx+1,cury,curd+1,curk));
            q1.push(make_tuple(curx-1,cury,curd+1,curk));
            q1.push(make_tuple(curx,cury+1,curd+1,curk));
            q1.push(make_tuple(curx,cury-1,curd+1,curk));
    
        }
    
        return -1 ;
    }

  
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) 
    {
        // code here
         return bfs_util(mat,k,n,m);
    }
};

static int arr[] = {0,-1,0,1,0};

int shotestPath(vector<vector<int>> mat, int n, int m, int k) 
{
    // code here
    vector<vector<int>>visisted(n,vector<int>(m,-1))    ;
    queue<vector<int>> q1 ; //x , y , current path , k left
    q1.push({0,0,0,k});
    while(!q1.empty())
    {
        vector<int> t1 = q1.front();
        int curx = t1[0] , cury = t1[1] , curd = t1[2] , curk = t1[3];
        q1.pop();
        if(curx<0||curx>=n||cury<0||cury>=m)
            continue ; //continue with loop

        //answer reached 
        if(curx==n-1&&cury==m-1)
            return curd;

        if(mat[curx][cury]==1)//wall found
        {
            if(curk<=0)
                continue ;
            curk-- ;
        }

        //NOT VISISTED 
        if(visisted[curx][cury]!=-1 && visisted[curx][cury]>=curk)//if better curk is not possible continue
            continue ;

        visisted[curx][cury] = curk ;//vsisted and curk is the better possibilty


        //queue push 4 direction 
        q1.push({curx+1,cury,curd+1,curk});
        q1.push({curx-1,cury,curd+1,curk});
        q1.push({curx,cury+1,curd+1,curk});
        q1.push({curx,cury-1,curd+1,curk});

    }

    return -1 ;

}






