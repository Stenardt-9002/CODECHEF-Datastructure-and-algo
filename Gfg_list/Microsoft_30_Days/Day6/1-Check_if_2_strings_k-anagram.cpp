// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day6/problem/check-if-two-strings-are-k-anagrams-or-not





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




bool areKAnagrams(string str1, string str2, int k) 
{
    // code here
    if(str1.size()!=str2.size())
        return false ;
    vector<int> hash11(26,0), hash12(26,0);
    for(auto c : str1)
        hash11[c-'a']++ ;
    
    for(auto c : str2)
        hash12[c-'a']++ ;

    int ans1 = 0 ;
    for (int i1 = 0; i1 < 26; i1++)
        ans1+=(abs(hash11[i1]-hash12[i1])) ;

    return (ans1<=2*k);
}







