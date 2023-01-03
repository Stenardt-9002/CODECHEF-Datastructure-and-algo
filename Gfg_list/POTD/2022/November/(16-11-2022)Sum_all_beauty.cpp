// https://practice.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings-1662962118/1








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

int beauty_val(vector<int>hash)
{
    int min_vl = INT_MAX, max_val = 1;
    for (int i = 0; i < 26; i++)
    {
        if(hash[i]!=0)
            min_vl = min(min_vl , hash[i]);
        
        max_val = max(max_val , hash[i]);
    }
    if(min_vl==INT_MAX)
        return 0 ;
    return max_val-min_vl ;
}



int beautySum(string s) 
{
    // Your code goes here
        
    int i,j,n = s.size();
    int ans1 = 0;
    for(i=0;i<n;i++)
    {
        vector<int>hash(26,0);
        for ( j = i; j < n; j++)
        {
            hash[s[j]-'a']++;
            ans1+=beauty_val(hash);
        }
    }
    return ans1 ;
}
















