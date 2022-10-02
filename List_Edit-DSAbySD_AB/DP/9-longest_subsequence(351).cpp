// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int longestSubsequence(int N, int A[])
{
    // code here
    
    vector<int> dp1(N,1);
    int ans1 = 1 ;
    for (int i = 0; i < N; i++)
        for (int j1 = i+1; j1 < N; j1++)
            if(abs(A[j1]-A[i])==1)
                dp1[j1] = max(dp1[j1],dp1[i]+1) ,ans1 = max(ans1,dp1[j1]);
    
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
    // cin>>testcase ;
    testcase = 2;
    while(testcase--)
    {
        int n ; cin>>n ;
        // int w ; cin>>w ;
        int *val = new int[n];
        // int *wt = new int[n];

        for (int i1 = 0; i1 < n; i1++)
            cin>>val[i1]     ;

        // for (int i1 = 0; i1 < n; i1++)
        //     cin>>wt[i1]     ;

        cout<<endl<<longestSubsequence(n,val);

        // cout<<knapSack(n,w,val,wt)<<endl ;

        delete []val ;//Sdelete []wt ;
    }    


    return 0 ;
}


