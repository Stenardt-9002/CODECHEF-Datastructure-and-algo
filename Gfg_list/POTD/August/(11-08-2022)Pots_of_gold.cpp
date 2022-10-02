// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1      
    



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int recursive_x(vector<int>&A,int start , int end);


// int recursive_y(vector<int>&A,int start , int end)
// {
//     if(start==end)
//         return A[start];
//     int pickfirst = A[start]+recursive_x(A,start+1 , end);
//     int picksecon = A[end]+recursive_x(A,start,end-1);
//     return max(pickfirst,picksecon);
// }
int recursive_x(vector<int>&A,int start , int end,vector<vector<int>>&dp1)
{
    if(dp1[start][end]!=-1)
        return dp1[start][end];
    if(start>end)
        return 0 ;
    if(start==end)
        return A[start];
    int pickfirst = A[start]+min(recursive_x(A,start+2 , end ,dp1), recursive_x(A,start+1 , end-1,dp1 ));
    int picksecon = A[end]+min(recursive_x(A,start+1 , end-1 ,dp1), recursive_x(A,start , end-2,dp1 ));
    return dp1[start][end] = max(pickfirst,picksecon);
}



// int maxCoins(vector<int>&A,int n)
// {
//     //Write your code here

//     vector<vector<int>>dp1(502,vector<int>(502,-1));
//     return recursive_x(A, 0 , n-1 ,dp1 );



//     //dp solution 


// }



int maxCoins(vector<int>&A,int n)
{
    //Write your code here

    vector<vector<int>>dp1(n,vector<int>(n,-1));
    for (int i1 = 0; i1 < n-1; i1++)
        dp1[i1][i1] = A[i1] ,dp1[i1][i1+1] = max(A[i1],A[i1+1]);
    
    dp1[n-1][n-1] = A[n-1];

    for (int length = 2; length < n; length++)
        for (int i1 = 0; i1+length < n; i1++)
        {
            int j1 = i1+length; 
            dp1[i1][j1] = max((A[i1]+min(dp1[i1+1][j1-1] , dp1[i1+2][j1] ) )  ,(A[j1] +min(dp1[i1+1][j1-1] , dp1[i1][j1-2])));
        }
        
    //dp solution 
    return dp1[0][n-1];
}



int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 

    int testcase ;
    int n;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        vector<int>array(n,0);
        for (int i1 = 0; i1 < n; i1++)
            cin>>array[i1];
        
        cout<<maxCoins(array , n)<<endl;
    }
    return 0 ;
}

