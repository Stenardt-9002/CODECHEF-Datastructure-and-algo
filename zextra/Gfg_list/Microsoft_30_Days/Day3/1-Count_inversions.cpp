// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day3/problem/inversion-of-array-1587115620












#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll merge_uitl(ll arr[] ,ll start ,ll mid ,ll end )
{
    vector<ll> a1(mid-start+1,0);
    vector<ll> b1(end-mid,0);

    for(ll i1 = 0 ;i1<mid-start+1 ; i1++)
        a1[i1] = arr[start+i1];
    
    for(ll i1 = 0 ;i1<end-mid ; i1++)
        b1[i1] = arr[mid+1+i1];
    
    ll ans1 = 0 ;

    ll i1 = 0 , j1=0 , k1 = start ;
    while(i1<mid-start+1 &&j1<end-mid)
    {
        if(a1[i1]<=b1[j1])
            arr[k1++] = a1[i1++];
        else 
        {
            arr[k1++] = b1[j1++];
            ans1+=(mid-start+1-i1);
        }
    }
    while(i1<mid-start+1)
    {
        arr[k1++] = a1[i1++];
    }

    while(j1<end-mid)
    {
        arr[k1++] = b1[j1++];
    }
    return ans1 ;
}


ll merge_Sort_count(ll arr[] ,ll start , ll end )
{
    if(start<end)
    {
        ll mid = (end+start)>>1 ;
        ll count1 = merge_Sort_count(arr, start , mid);
        ll count2 = merge_Sort_count(arr, mid+1 , end);
        ll count3 = merge_uitl(arr , start , mid , end );
        return count1+count2+count3 ;
    }
    return 0 ;
}


long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return merge_Sort_count(arr, 0 , N-1) ;
}






int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    ll n ;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        ll *array_in = new ll[n];
        for(ll i1 = 0 ; i1<n;i1++)
            cin>>array_in[i1] ;
        cout<<endl ;
    }
    return 0 ;
}







