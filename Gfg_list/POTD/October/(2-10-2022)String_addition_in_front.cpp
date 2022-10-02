// https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1





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

vector<int> lps_create(string s)
{
    string s1 = s ;
    reverse(s1.begin(),s1.end());

    s = s+'&'+s1 ;
    int n = s.length() ;
    vector<int> lps_Array(n,0);
    int i1 = 1 ,ptr =0;
    lps_Array[0] = 0 ;
    while (i1<n)
    {
        if(s[i1]==s[ptr])
            lps_Array[i1++] = ++ptr ;
        else 
        {
            if(ptr!=0)
                ptr = lps_Array[ptr-1];
            else 
                lps_Array[i1++] = 0;
        }
    }
    
    return lps_Array ;
}

int minChar(string str)
{
        //Write your code here
    vector<int> character = lps_create(str);
    return str.length()-character.back();
}


