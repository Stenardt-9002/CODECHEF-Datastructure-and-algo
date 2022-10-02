// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day8/problem/capacity-to-ship-packages-within-d-days

    




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

bool func_allowed(int arr[] ,int N ,int D ,ll timeallowed)
{
    int i1 = 0 , j1=0 ;
    ll current_sum = 0 ;
    while (i1<N&&j1<D)
        if(arr[i1] + current_sum<=timeallowed)
            current_sum += arr[i1++];
        else 
            j1++ , current_sum = 0 ;

    if(i1!=N)
        return false ;
    return true ;    
}

int leastWeightCapacity(int arr[], int N, int D) 
{
    // code here
    ll sum1 = 0 ;
    for (int i1 = 0; i1 < N; i1++)
        sum1+=arr[i1];


    ll low1 = 1ll ;    
    ll high1 = sum1 ;
ll ans1 = high1 ;
    if(D==1)
        return high1 ;

    while(low1<=high1)
    {
        ll mid = (low1+high1)>>1;
        if(func_allowed(arr , N , D , mid))
        {
            ans1 = mid ;
            high1 = mid-1 ;
        }
        else 
            low1 = mid+1 ;
    }
    return ans1 ;
}


