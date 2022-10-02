// https://practice.geeksforgeeks.org/batch-problems/array-pair-sum-divisibility-problem3257/0/?track=microsoft-29days-day2&batchId=636



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

char nonrepeatingCharacter(string S)
{
    //Your code here

    vector<int>char_hash(26,0);

    for(auto ch:S)
        char_hash[ch-'a']++ ;
    
    for(auto ch:S)
        if(char_hash[ch-'a']==1)
            return ch ;


    return '$';
}
