// https://practice.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1



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

vector<int> findLeastGreater(vector<int>& arr, int n) 
{
    set<int>s1 ;
    vector<int>ans1(n);
    int i1 = n;
    while(i1-->0)
    {
        auto it = s1.upper_bound(arr[i1]);
        if(s1.empty()||it==s1.end())
            ans1[i1] = -1 ;
        else 
            ans1[i1] = *it ;
        s1.insert(arr[i1]);
    }
    return ans1 ;
}

