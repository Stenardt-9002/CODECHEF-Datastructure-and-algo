// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1






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






int minDifference(int arr[], int n)  
{ 
    // Your code goes here
    if(n==1)
        return arr[0];
    ll sum1 = 0 ;
    for (int i1 = 0; i1 < n; i1++)
        sum1+=arr[i1];

    vector<vector<bool>> dp1(n,vector<bool>(sum1+1,false));
    for (int i1 = 0; i1 < n; i1++)
        dp1[i1][0] = true ;
    
    dp1[0][arr[0]] = true;
    for (int i1 = 1; i1 < n; i1++)
        for (int itr_sum = 0; itr_sum < sum1+1; itr_sum++)
            if(itr_sum>=arr[i1] && dp1[i1-1][itr_sum-arr[i1]])
                dp1[i1][itr_sum] = true ;//inclusive
            else if(dp1[i1-1][itr_sum])
                dp1[i1][itr_sum] = true ;//non inclusive

        
    ll ans1_min = INT_MAX ;    
    for (int i1 = 0; i1 <=sum1; i1++)
        if(dp1[n-1][i1])
        ans1_min = min(ans1_min,abs(sum1-i1-i1));
    
    return ans1_min ;
} 







