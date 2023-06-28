// https://practice.geeksforgeeks.org/problems/7488b7721e8aa5e5fc37d56af8b9c89e329c796f/1











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
        int modulo(string s,int m)
        {
            //code here
            int n = s.length();
            int ans = 0,mod = 1 ;
            for(int i = n-1 ; i>=0 ; i--)
            {
                if(s[i]=='1')
                    ans = (ans+mod)%m;
                mod = (mod*2);
                mod = mod%m ;   
            }
            return ans%m ; 
            
        }
};