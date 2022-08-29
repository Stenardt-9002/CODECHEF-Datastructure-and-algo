



// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




	// int lps(string s) {
	//     // Your code goes here
	// }
int lps(string s) 
{
    // Your code goes here

    int n = s.length() ;
    if(n<2)   
        return 0;
    int len = 0,i1 = 1;
    while (i1<n)
    {
        if (s[i1]==s[len])
        {
            len++ ; 
            i1++ ;
        }
        else
        {
            i1 = i1-len+1 ;
            len = 0 ;
        }
    }
    return len;
}   
