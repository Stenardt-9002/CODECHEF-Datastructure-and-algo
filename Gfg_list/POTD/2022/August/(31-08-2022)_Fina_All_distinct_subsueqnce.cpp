// https://practice.geeksforgeeks.org/problems/merging-details/1



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


vector<int> DistinctSum(vector<int>nums)
{
    // Code here
    int n = nums.size();
    set<int> ans1 ;
    ans1.insert(0);
    int sum1 = 0 ;
    for(auto x : nums)
        sum1+=x ;
    
    vector<vector<bool>>dp1(n,vector<bool>(sum1+1 ,false ));
    for (int i1 = 0; i1 < n; i1++)
        dp1[i1][0] = true ; 
    //always 0 always possible 
    dp1[0][nums[0]] = true ;
    for (int eachind = 1; eachind < n; eachind++)
        for (int eachsum = 0; eachsum < sum1+1; eachsum++)
        {
            bool pick = dp1[eachind-1][eachsum];
            bool nonpick = false ;
            if(eachsum>=nums[eachind])
                nonpick = dp1[eachind-1][eachsum-nums[eachind]];
            
            dp1[eachind][eachsum] = pick|nonpick ;
        }
    for (int eachsum = 0; eachsum < sum1+1; eachsum++)
        if(dp1[n-1][eachsum])
            ans1.insert(eachsum);
            
    

    

    vector<int> ans2(ans1.begin(),ans1.end());
    return ans2 ;
}