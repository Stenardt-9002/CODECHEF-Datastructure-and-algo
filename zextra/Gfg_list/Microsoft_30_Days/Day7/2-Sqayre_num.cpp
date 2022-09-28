// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day7/problem/square-root


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    if(x<=0)
        return 0 ;
    ll low1 = 1 ; 
    ll high1 = x ; 
    ll ans1 = 1 ;
    while(low1 <high1)
    {
        ll mid1 = low1+(high1-low1)/2 ;
        if(mid1*mid1 <= x)
        {
            ans1 = mid1 ;
            low1 = mid1 +1 ;
        }
        else 
            high1 = mid1 ;
    }
    return ans1 ;
}

int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    ll n;// ,k;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        cout<<floorSqrt(n);
        cout<<endl;
    }
    return 0 ;
}