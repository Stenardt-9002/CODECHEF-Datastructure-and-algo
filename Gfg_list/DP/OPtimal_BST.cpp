














#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int lld;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;









class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        vector<vector<lld>> dp1(n , vector<lld>(n,0));
        for (lld i = 0; i < n; i++)
            dp1[i][i] = freq[i];

        for (lld lneg = 2; lneg <=n; lneg++)
        {
            for (lld start = 0; start <n-lneg+1; start++)
            {
                lld end = start+lneg-1 ;
                dp1[start][end] = INT_MAX ;
                lld offset_sum = 0 ;
                for (lld i = start; i <=end; i++)
                    offset_sum+=freq[i];
                
                for (lld r = start; r <=end; r++)
                    dp1[start][end] = min(dp1[start][end] , ((r>start)?dp1[start][r-1]:0)+((r<end)?dp1[r+1][end]:0)+offset_sum  );
                
            }
        }

        return dp1[0][n-1];
    }
};