// https://practice.geeksforgeeks.org/problems/maximum-sub-string-after-at-most-k-changes3220/1








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




int func_char(string s,int n,int k,char ch)
{
    int ans1 = 1;
    int cnt = 0,l_ptr = 0 ,r_ptr = 0 ;


    while (r_ptr<n)
    {
        if(s[r_ptr]!=ch)    
            cnt++ ;

        while (cnt>k&&l_ptr<n)
        {
            if(s[l_ptr]!=ch)
                cnt--;
            l_ptr++ ;
        }
        
        ans1 = max(ans1 , r_ptr-l_ptr+1);
        r_ptr++;
    }    
    return ans1 ;
}






int characterReplacement(string s, int k)
{
    // Code here
    int n = s.length();
    int ans1 = 0 ;
    for (int i1 = 0; i1 < 26; i1++)
        ans1 = max(ans1,func_char(s,n,k,i1+'A'));
    return ans1 ; 
}








