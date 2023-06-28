
// https://practice.geeksforgeeks.org/problems/32dc957908c2eb8beeeaeedf81f37df20d37c308/1









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
    int minimumSum(string s) {
        // code here
        int ans= 0 ,n = s.size();
        for(int i = 0 ; i<n/2; i++)
        {
            if(s[i]=='?' && s[n-1-i]!='?')
                s[i] = s[n-1-i];
            else if(s[i]!=s[n-1-i] && s[i]!='?' && s[n-i-1]!='?')
                return -1 ;
        }
        char prevchar = '.';
        for(int i = 0 ; i<n/2; i++)
            if(s[i]!='?')
            {
                if(prevchar=='.')
                    prevchar = s[i];
                else if(s[i]!=prevchar)
                    ans+=(abs(s[i]-prevchar));
                prevchar = s[i];
            }
        
        return ans*2 ;
    }
};