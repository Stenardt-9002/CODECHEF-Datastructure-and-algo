// https://practice.geeksforgeeks.org/problems/break-a-number5913/1











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









int waysToBreakNumber(int N)
{
    int mod = 1000000007 ;
    long long int n = N;
    long long int val = ((n+1)*(n+2))/2;
    val = val%mod ;
    return val ;
}

