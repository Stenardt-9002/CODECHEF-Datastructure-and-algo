
// https://leetcode.com/problems/longest-common-subsequence/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int longestCommonSubsequence(string text1, string text2) 
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>>dp1(n+1,vector<int>(m+1,0));

    // 0 length string has not subsequence (0 length)

    for (int i1 = 1; i1 <=n; i1++)
        for (int j1 = 1; j1 <=m; j1++)
            if(text1[i1-1]==text2[j1-1])
                dp1[i1][j1] = 1+dp1[i1-1][j1-1];
            else 
                dp1[i1][j1] = max(dp1[i1-1][j1],dp1[i1][j1-1]);


    return dp1[n][m];//length of maximum common subsequence m ,n string
}


