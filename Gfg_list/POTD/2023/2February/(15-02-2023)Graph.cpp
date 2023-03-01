



// https://practice.geeksforgeeks.org/problems/6cb0782855c0f11445b8d70e220f888e6ea8e22a/1














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



static int arr[] = {0,-1,0,1,0};
class Solution{   
public:
    int water_flow(vector<vector<int>> &mat,int N,int M)
    {
        // Write your code here.
        if(N==1 && M==1)
            return 1 ;
        
        vector<vector<bool>>indian_vi(N,vector<bool>(M,false));
        vector<vector<bool>>arabian_vi(N,vector<bool>(M,false));
        queue<pair<int,int>> q1 ;
        int ans = 0 ;
        for (int i1 = 0; i1 < N; i1++)
        {
            indian_vi[i1][0] = true ; 
            q1.push({i1,0});
        }
        for (int i1 = 0; i1 < M; i1++)
        {
            indian_vi[0][i1] = true ; 
            q1.push({0,i1});
        }
        while (!q1.empty())
        {
            int srcx = q1.front().first ; 
            int srcy = q1.front().second ; 
            q1.pop();
            for (short i = 0; i < 4; i++)
                {
                    int newx = srcx+arr[i];
                    int newy = srcy+arr[i+1];
                    if(newx>=0 && newy>=0 && newx<N && newy<M && !indian_vi[newx][newy] && mat[newx][newy]>=mat[srcx][srcy])
                    {
                        indian_vi[newx][newy] = true ;
                        q1.push({newx , newy});
                    }
                }
        }
        
    //arabian 
        for (int i1 = 0; i1 < N; i1++)
        {
            arabian_vi[i1][M-1] = true ; 
            q1.push({i1,M-1});
        }
        for (int i1 = 0; i1 < M; i1++)
        {
            arabian_vi[N-1][i1] = true ; 
            q1.push({N-1,i1});
        }        
    
        while (!q1.empty())
        {
            int srcx = q1.front().first ; 
            int srcy = q1.front().second ; 
            q1.pop();
            for (short i = 0; i < 4; i++)
                {
                    int newx = srcx+arr[i];
                    int newy = srcy+arr[i+1];
                    if(newx>=0 && newy>=0 && newx<N && newy<M && !arabian_vi[newx][newy] && mat[newx][newy]>=mat[srcx][srcy])
                    {
                        arabian_vi[newx][newy] = true ;
                        q1.push({newx , newy});
                    }
                }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                ans+=(arabian_vi[i][j]&&indian_vi[i][j]);
        


        return ans  ;

    }
};


