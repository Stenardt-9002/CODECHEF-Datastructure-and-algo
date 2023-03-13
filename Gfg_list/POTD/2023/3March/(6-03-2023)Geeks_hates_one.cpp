// https://practice.geeksforgeeks.org/problems/07e45fe40846bc670ad2507d2c649304699768b9/1













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



































class Solution {

  public:
    int noConseBits(int n) 
    {
        // code here
        for(int i=31;i>=2;i--){
            int one = (1<<i)&n;
            int two = (1<<(i-1))&n;
            int three = (1<<(i-2))&n;
            if(one && two && three)
                n = (n^three);
            
        }
        return n;

    }
};