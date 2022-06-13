	
    


// https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


// int dp_var[100][909];
int TotalCount(string str)
{
    // Code here
    int n = str.length();
    vector<vector<int>> dp1(101,vector<int>(999,-1));
    return resurcive(0,0,n,str,dp1);
}
int resurcive(int pos,int prev_sum,int length, string str,vector<vector<int>> &dp_var)
{
    if(pos==length)
        return 1;
    
    if(dp_var[pos][prev_sum]!=-1 )
        return dp_var[pos][prev_sum];

    dp_var[pos][prev_sum]= 0;
    int res = 0,sum = 0;
 
    for (int i = pos; i < length; i++)
    {
        sum += (str[i] - '0');
        if (sum >= prev_sum)//constrint
            res += resurcive(i + 1, sum,length, str,dp_var);
    }
 
    dp_var[pos][prev_sum] = res;
    return res;
}