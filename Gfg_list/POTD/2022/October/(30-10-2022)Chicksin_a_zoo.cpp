// https://practice.geeksforgeeks.org/problems/chicks-in-a-zoo1159/1



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



long long int NoOfChicks(int n)
{
    // Code here
    // vector<ll> dp1(n+1,0);
    // vector<ll> chickcount(n+1,0);
    // dp1[0] = 1;
    // chickcount[0] = 1;
    // ll sum1 = 1;
    // for (int i1 = 1; i1 < n; i1++)
    // {
    //     if(i1<6)
    //     {
    //         chickcount[i1] = sum1*2 ;
    //         sum1 = 3*sum1 ;
    //         dp1[i1] = sum1 ;
    //     }
    //     else
    //     {
    //         dp1[i1] = (dp1[i1-1]-chickcount[i1-6])*3 ;
    //         chickcount[i1] = (dp1[i1-1]-chickcount[i1-6])*2 ;
    //     }
        
    // }
    // return dp1[n-1]    ;

    vector<ll> dp1(7,0);
    vector<ll> chickcount(7,0);
    dp1[0] = 1;
    chickcount[0] = 1;
    ll sum1 = 1;
    for (int i1 = 1; i1 < n; i1++)
    {
        if(i1<6)
        {
            chickcount[i1%7] = sum1*2 ;
            sum1 = 3*sum1 ;
            dp1[i1%7] = sum1 ;
        }
        else
        {
            dp1[i1%7] = (dp1[(i1-1)%7]-chickcount[(i1-6)%7])*3 ;
            chickcount[i1%7] = (dp1[(i1-1)%7]-chickcount[(i1-6)%7])*2 ;
        }
        
    }
    return dp1[(n-1)%7]    ;
}


