
// https://practice.geeksforgeeks.org/problems/bbt-counter4914/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



    long long int countBT(int h) { 
        // code here
        int MOD1 = 1000000007;
        vector<long long int>dp1(h+1,0);
        dp1[0] = dp1[1] = 1;
        for(int i1 = 2 ;i1<=h ; i1++)
            dp1[i1] = ((2*(dp1[i1-1])*(dp1[i1-2]) ) +((dp1[i1-1])*(dp1[i1-1]))) , dp1[i1] = dp1[i1]%MOD1;
            
        return dp1[h]%MOD1;
    }