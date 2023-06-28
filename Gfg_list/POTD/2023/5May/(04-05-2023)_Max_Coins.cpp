// https://practice.geeksforgeeks.org/problems/111fb97b983399c0ee9f34b7bae18ac76bf6f07a/1










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









class Solution{
public:


    int solve_util(vector<vector<int>> &ranges , int ind , int rem , vector<vector<int>> &dp1)
    {
        if(rem == 0 || ind == ranges.size())
            return 0 ; 
        if(dp1[ind][rem]!=-1)
            return dp1[ind][rem];
        int nottake = solve_util(ranges,ind+1,rem,dp1);
        int take = ranges[ind][2];
        int low = ind+1 , high = ranges.size()-1;
        int ans = ranges.size();
        while (low<=high)
        {
            int mid = low+(high-low)/2 ; 
            if(ranges[mid][0]>=ranges[ind][1])
                ans = mid ,high = mid-1 ; 
            else 
                low = mid+1;            
        }
        take+=solve_util(ranges,ind,rem-1,dp1);
        return dp1[ind][rem] = max(take, nottake);
        
    }



    int maxCoins(int n,vector<vector<int>> &ranges)
    {
        // Code here
        sort(ranges.begin(),ranges.end());
        vector<vector<int>>dp1(n,vector<int>(3,-1));
        return solve_util(ranges,0,2,dp1);
    }
};
























