// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1









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



// vector<int> recursion(int N , vector<int>)
    vector<int> minPartition(int N)
    {
        // code here
        set<int> s1 = {1,2,5,10,20,50,100,200,500,2000};
        vector<int> ans1 ;
        int lower_val;
        while (N>0)
        {
            lower_val = *(--s1.upper_bound(N))    ;
            N-=lower_val;
            ans1.push_back(lower_val);
        }
        
        return ans1 ;
    }









