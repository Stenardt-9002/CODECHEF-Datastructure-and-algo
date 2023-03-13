// https://practice.geeksforgeeks.org/problems/ad6699d4aaf84c74b119fac3b65e9ceb3fc8ef14/1













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








class Solution
{
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) 
    {
        // code here
        int n = N ;
        vector<int> ans ;
        vector<int> dp1(N,0);
        map<int,int> dict1 ; 
        for(int i = n-1;i>=0 ;--i)
            dp1[i] = ++dict1[A[i]];
    
    
        for(auto vec : Q)    
        {
            int ind = vec[0];
            int ind2 = vec[1];
            int k = vec[2];
            int count = 0 ;
            for(int i = ind;i<=ind2;++i)
                if(dp1[i]==k)
                    count++ ;
            ans.push_back(count);
        }
        
        return ans ; 
    }
};