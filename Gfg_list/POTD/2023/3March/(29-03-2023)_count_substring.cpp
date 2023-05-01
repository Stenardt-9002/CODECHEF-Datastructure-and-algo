// https://practice.geeksforgeeks.org/problems/839d6ba2c2e4c669ba9d9d9f32ad20118937284e/1












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
    int countSubstring(string S)
    {
        // code here
        int ans = 0 ;
        int n = S.length();
        int small =0 , large = 0 ;
        
        for(int second = 0;second<n;++second)
        {
            char c = S[second];
            if(c>='a' && c<='z')
                small++;
            else
                large++ ;
            int curs = small ; 
            int curl = large ; 
            for(int first = 0 ; first<second ; first++)
            {
                if(curs == curl)
                    ans++ ;
                
                char c = S[first];
                if(c>='a' && c<='z')
                    curs--;
                else
                    curl-- ;
            }
        }
        return ans ;
        
        
    }
};