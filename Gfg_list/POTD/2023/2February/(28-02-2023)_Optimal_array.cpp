// https://practice.geeksforgeeks.org/problems/d4aeef538e6dd3280dda5f8ed7964727fdc7075f/1







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
    vector<int> optimalArray(int n,vector<int> &a)
    {
        // Code here
        vector<int> ans = {0};
        for (int i = 1; i < n; i++)
            ans.push_back(ans.back()+(a[i]-a[i/2]));
        
        return ans ;
    }
};






















