// https://practice.geeksforgeeks.org/problems/earthquake-and-the-paint-shop4518/1





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


struct alphanumeric{
    string word ;
    int count ;
};


vector<alphanumeric> sortedStrings(int N, vector<string> A) 
{
// code here
    map<string, int> map1 ;
    for(auto c : A)
        map1[c]++ ;

    vector<alphanumeric> ans1 ;

    for(auto key:map1)
        ans1.push_back({key.first, key.second});


    return ans1 ;


}












