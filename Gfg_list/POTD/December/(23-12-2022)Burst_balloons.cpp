









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
    int maxCoins(int N, vector<int> &arr) 
    {
        // code here
            vector<int> newarray(N+2,1);
        for (int i = 0; i < N; i++)
            newarray[i+1] = arr[i];
        
    
    
        vector<vector<int>>dp1(N+2 , vector<int>(N+2,0));
    
        for (int length = 1; length < N+1; length++)
            for (int left = 1; left < N-length+2; left++)
            {
                int right = left+length-1 ;
                for (int last = left; last <=right; last++)
                    dp1[left][right] = max(dp1[left][right] , dp1[left][last-1] + newarray[last]*newarray[left-1]*newarray[right+1]  +dp1[last+1][right]);
                
            }
            
        return dp1[1][N];
    }
};