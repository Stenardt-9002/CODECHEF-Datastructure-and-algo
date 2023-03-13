// https://practice.geeksforgeeks.org/problems/77e1c3e12cd148f835d53eb168d4472b2ff539fa/1










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
    vector<int> findMaxRow(vector<vector<int>> mat, int N) 
    {
        //code here
        int n = N;
        int row_val = -1 ;int ones_c = -1;
        for(int i= 0 ; i<n;i++)
        {
            int pos1 = lower_bound(mat[i].begin(),mat[i].end(),1)-mat[i].begin() ;
            if(ones_c<N-pos1)
            {
                ones_c =N-pos1;
                row_val = i ;
            }
        }
        return {row_val ,ones_c};
    }
};