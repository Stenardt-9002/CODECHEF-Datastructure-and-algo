// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int lcs(int x, int y, string s1, string s2)
{
    // your code here

    vector<vector<int>> dp1(x+1, vector<int>(y+1,0));
    for (int i1 = 1; i1 <=x; i1++)
        for (int j1 = 1; j1 <=y; j1++)
            if(s1[i1-1]==s2[j1-1])
                dp1[i1][j1] = dp1[i1-1][j1-1]+1;
            else 
                dp1[i1][j1] = max(dp1[i1-1][j1],dp1[i1][j1-1]);

    return dp1[x][y];
}



int LongestRepeatingSubsequence(string str)
{
    // Code here
    int n = str.length();
    vector<vector<int>>dp1(n+1,vector<int>(n+1,0));

    for (int i1 = 1; i1 <=n; i1++)
        for (int j1 = 1; j1 <=n; j1++)
            if(str[i1-1]==str[j1-1]&& i1!=j1)    
                dp1[i1][j1] = dp1[i1-1][j1-1]+1 ;
            else 
                dp1[i1][j1] = max(dp1[i1-1][j1] , dp1[i1][j1-1]);

    return dp1[n][n];

}