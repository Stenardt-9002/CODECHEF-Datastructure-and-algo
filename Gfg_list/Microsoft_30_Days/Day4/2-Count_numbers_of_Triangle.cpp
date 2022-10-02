// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day4/problem/count-possible-triangles-1587115620




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int findNumberOfTriangles(int arr[], int n)
{
    // code here
    int i1 = 0 , j1 = 0 , k1 = 0 , ans1 = 0 ;
    sort(arr,arr+n);
    for (k1 = n-1; k1 >=0; k1--)
    {
        i1 =0 ; j1 = k1-1 ;
        //two pointers
        while(i1<j1)
            if(arr[i1]+arr[j1]>arr[k1])
            {
                ans1+=(j1-i1);
                j1-- ;
            }
            else 
                i1++ ;

    }
    return ans1 ;
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






