


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int remAnagram(string str1, string str2)
{
// Your code goes here
    vector<int> char_had1sh(26,0);
    vector<int> char_had2sh(26,0);


    for (auto ch : str1)
        char_had1sh[ch-'a']++ ;


    for (auto ch : str2)
        char_had2sh[ch-'a']++ ;

    int ans1 = 0 ;
    for (int i1 = 0; i1 < 26; i1++)
        ans1+=(abs(char_had1sh[i1] - char_had2sh[i1]));
    

    return ans1 ;    
}