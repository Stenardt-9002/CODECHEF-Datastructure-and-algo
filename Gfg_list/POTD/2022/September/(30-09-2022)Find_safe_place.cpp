// https://practice.geeksforgeeks.org/problems/tom-and-jerry1325/1




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



int safePos(int n, int k) 
{
    // code here
    if(n==1)
        return 1 ;
    
    return (safePos(n-1,k)+k-1)%n+1;
}



