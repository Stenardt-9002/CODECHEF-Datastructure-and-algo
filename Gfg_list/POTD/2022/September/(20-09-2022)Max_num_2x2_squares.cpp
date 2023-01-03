// https://practice.geeksforgeeks.org/problems/maximum-number-of-22-squares/1





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

const long long int mod2 =  1e18 ;



long long int numberOfSquares(long long int base)
{
    //code here
    long long int ans1 = (base-2)/2;
    ans1 = (ans1)*(ans1+1)/2 ;
    return ans1 ;

}



