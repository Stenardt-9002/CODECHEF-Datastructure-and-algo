







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


long long int numoffbt(long long int arr[], int n)
{
    // Your code goes here
    set<long long int> set_1 ;
    for (int i1 = 0; i1 < n; i1++)
        set_1.insert(arr[i1]);

    unordered_map<ll , ll> dp1 ;
    for(auto x: set_1)
        dp1[x] = 1;
    for(auto ele : set_1)
    {
        for(auto x : set_1)
            if(x<ele)
            {
                if(ele%x == 0)
                {
                    long long int quotient = ele/x ;
                    if(x==quotient)
                    {
                        dp1[ele]+=(dp1[x]*dp1[x]);
                        dp1[ele]%=MOD1;
                    }
                    else if(set_1.find(quotient)!=set_1.end())
                    {
                        dp1[ele]+=(2*dp1[x]*dp1[quotient]);
                        dp1[ele]%=MOD1;
                    }   
                }
            }
            else 
                break ;
    }
    ll sum1 = 0 ;
    for(auto kry : dp1)
    {
        sum1+=kry.second ;
        sum1 = sum1%MOD1 ;
    }
    return sum1 ;
}



long long int numoffbt(long long int arr[], int n)
{
    // Your code goes here
        set<long long int> set_1 ;
    for (int i1 = 0; i1 < n; i1++)
        set_1.insert(arr[i1]);

    unordered_map<ll , ll> dp1 ;
    for(auto x: set_1)
        dp1[x] = 1;
    for(auto ele : set_1)
    {
        long long int sqt = sqrt(ele)+1 ;
        auto it = set_1.upper_bound(sqt);
        for(auto it1 = set_1.begin();it1!=it ; it1++)
            {
                long long int x = *it ;
                if(ele%x == 0)
                {
                    long long int quotient = ele/x ;
                    // if(x==quotient)
                    // {
                    //     dp1[ele]+=(dp1[x]*dp1[x]);
                    //     dp1[ele]%=MOD1;
                    // }
                    // else
                    if(set_1.find(quotient)!=set_1.end())
                    {
                        dp1[ele]+=(dp1[x]*dp1[quotient]);
                        dp1[ele]%=MOD1;
                        
                    }   
                }
            }

    }
    ll sum1 = 0 ;
    for(auto kry : dp1)
    {
        sum1+=kry.second ;
        // cout<<kry.second<<endl ;
        sum1 = sum1%MOD1 ;
    }
    return sum1 ;
}




long long int numoffbt(long long int arr[], int n)
{
    // Your code goes here
        set<long long int> set_1 ;
    for (int i1 = 0; i1 < n; i1++)
        set_1.insert(arr[i1]);

    unordered_map<ll , ll> dp1 ;
    for(auto x: set_1)
        dp1[x] = 1;
    for(auto ele : set_1)
    {
        for(auto x : set_1)
            if(x<ele)
            {
                if(ele%x == 0)
                {
                    long long int quotient = ele/x ;
                    // if(x==quotient)
                    // {
                    //     dp1[ele]+=(dp1[x]*dp1[x]);
                    //     dp1[ele]%=MOD1;
                    // }
                    // else 
                    if(set_1.find(quotient)!=set_1.end())
                    {
                        dp1[ele]+=(dp1[x]*dp1[quotient]);
                        dp1[ele]%=MOD1;
                        
                    }   
                }
            }
            else 
                break ;
    }
    ll sum1 = 0 ;
    for(auto kry : dp1)
    {
        sum1+=kry.second ;
        // cout<<kry.second<<endl ;
        sum1 = sum1%MOD1 ;
    }
    return sum1 ;
}
