// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    // vector<vector<int>> dp1(N,vector<int>(W+1,0)) ;
    // int ans1 = 0 ;
    // // dp[i,j] contains value 
    // for (int i1 = 1; i1 <=W; i1++)
    //     for (int j1 = 0; j1 < N; j1++)
    //         if(i1-wt[j1]>=0)
    //         {
    //             dp1[j1][i1]+=(dp1[j1][i1-wt[j1]]+val[j1]);
    //             ans1 = max(ans1 , dp1[j1][i1]);
    //         }
        



    vector<int>dp2(W+1,0);
    int ans1 = 0 ;
    // dp[i,j] contains value 
    for (int i1 = 1; i1 <=W; i1++)
        for (int j1 = 0; j1 < N; j1++)
            if(i1-wt[j1]>=0)
            {
                dp2[i1]=max(dp2[i1-wt[j1]]+val[j1] ,dp2[i1]);
                ans1 = max(ans1 , dp2[i1]);
            }
        

    
    // cout<<"DEBUFG1"<<endl ;
    // for (int i1 = 0; i1 <N; i1++)
    // {
    //     for (int j1 = 0; j1 <=W; j1++)
    //         cout<<" "<<dp1[i1][j1];
    //     cout<<endl ;
    // }
    // cout<<endl ;

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
    cin>>testcase ;
    while(testcase--)
    {
        int n ; cin>>n ;
        int w ; cin>>w ;
        int *val = new int[n];
        int *wt = new int[n];

        for (int i1 = 0; i1 < n; i1++)
            cin>>val[i1]     ;

        for (int i1 = 0; i1 < n; i1++)
            cin>>wt[i1]     ;



        cout<<knapSack(n,w,val,wt)<<endl ;

        delete []val ;delete []wt ;
    }    


    return 0 ;
}