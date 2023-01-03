// https://practice.geeksforgeeks.org/problems/help-ishaan5837/1



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

bool prime_check(int n)
{
    if(n<2)
        return false ;
    int limit_n = sqrt(n)+1 ;
    for (int i1 = 2; i1 < limit_n; i1++)
        if(n%i1==0)
            return false ;
    return true ;
}



int NthTerm(int N)
{
    // Code here
    int distance = 0;
    if(prime_check(N))
        return 0 ;
    while(true)
    {
        distance++ ;
        if(prime_check(N-distance)||prime_check(N+distance))
            return distance ;
    }

    return -1 ;


}

