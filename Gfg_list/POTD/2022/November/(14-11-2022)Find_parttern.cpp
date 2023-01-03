// https://practice.geeksforgeeks.org/problems/find-patterns0606/1







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




int numberOfSubsequences(string S, string W)
{
    // code here 
    //lcs 
        int m = S.size();
        int n = W.size();
    
        vector<vector<int>> dp1(m+1,vector<int>(n+1,0));
        if(m==0||n==0)
            return 0 ; 
        for (int i1 = 0; i1 <=m; i1++)
            for (int j1 = 0; j1 <=n; j1++)
                if(i1==0||j1==0)
                    dp1[i1][j1] = 0 ;
                else if(S[i1-1]==W[j1-1])
                    dp1[i1][j1] = dp1[i1-1][j1-1]+1;
                else
                    dp1[i1][j1] = max(dp1[i1-1][j1] , dp1[i1][j1-1]);
    
        if(n==dp1[m][n])
        {
            int ans1 = 0,ptr = 0;
            vector<bool> done(m,false);
            for (int k = 0; k < m/n +1; k++)
            {
                ptr=0 ;
                for (int i1 = 0; i1 < m; i1++)
                {
                    if(!done[i1]&& ptr<n&& W[ptr]==S[i1])
                    {
                        ptr++;
                        done[i1] = true ;
                    }
                }
                ans1+=(ptr==n);
            }
            return ans1 ;
        }  
        return 0 ;

}





