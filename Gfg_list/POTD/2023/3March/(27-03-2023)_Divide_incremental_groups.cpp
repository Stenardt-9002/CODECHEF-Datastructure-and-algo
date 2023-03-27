// https://practice.geeksforgeeks.org/problems/c239059f6d110e6778cc2f2a1ab58ffd0a3d64ca/1











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
    int countWaystoDivide(int N, int K) {
        // Code here
        if(N==K || K==1)
            return 1 ;
        vector<vector<vector<int>>> dp1(N+1 , vector<vector<int>>(N+1 , vector<int>(K+1, 0)));
        int ans = 0 ;
        for(int i = 0 ; i<=N ; ++i)
            dp1[i][N][0] = 1 ;
        for(int i=N-1;i>=0;--i)
            for(int sum1=N ; sum1>=0 ; --sum1)
                for(int k = 0 ;k<=K;++k )
                {
                    if(sum1+i+1<=N)
                        dp1[i][sum1][k] = dp1[i][sum1+i+1][k-1]+dp1[i+1][sum1][k];
                    else 
                        dp1[i][sum1][k] = dp1[i+1][sum1][k];
                    
                }
        return dp1[0][0][K] ;        

    }
};