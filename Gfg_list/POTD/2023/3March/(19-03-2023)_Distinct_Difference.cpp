// https://practice.geeksforgeeks.org/problems/c670bf260ea9dce6c5910dedc165aa403f6e951d/1












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
    vector<int> getDistinctDifference(int N, vector<int> &A) 
    {
        // code here
        vector<int> ans ;
        unordered_map<int,int> left_hash , right_hash ;
        int unique_count_left = 0 , unique_right_count =0 ;
        for (int i = 0; i < N; i++)
            unique_right_count+=(++right_hash[A[i]]==1);
        
        if(--right_hash[A[0]]==0)
            unique_right_count--;

        ans.push_back(-unique_right_count);
        for (int i = 1; i < N; i++)
        {
            if(++left_hash[A[i-1]]==1)
                unique_count_left++ ;
            if(--right_hash[A[i]]==0)
                unique_right_count-- ;

            ans.push_back(unique_count_left-unique_right_count);
        }
        


        return ans ;
    }
};