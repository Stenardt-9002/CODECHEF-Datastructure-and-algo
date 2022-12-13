// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day15/problem/reverse-each-word-in-a-given-string1001




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


    string reverseWords (string s)
    {
        //code here.

        string temp = "";
        string ans1 ="";
        for (int i = 0; s[i]; i++)
        {
            if(s[i]=='.')
            {
                reverse(temp.begin(),temp.end());
                ans1+=temp ;
                temp = "";
                ans1+=".";
            }
            else 
                temp+=s[i];
        }
        reverse(temp.begin(),temp.end());
        ans1+=temp ;

        return ans1 ;
    }






