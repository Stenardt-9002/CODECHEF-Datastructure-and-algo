// https://practice.geeksforgeeks.org/problems/fill-up-buckets3500/1










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







int totalWays(int n, vector<int>capacity) 
{
    // code here
    sort(capacity.begin(),capacity.end());
    ll ans1 = 1;
    for (int i1 = 0; i1 < n; i1++)
        ans1*=(capacity[i1]-i1) , ans1%=MOD1;
    

    return ans1;
}




