// https://practice.geeksforgeeks.org/problems/array-removals/1








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


//two ptr method
int removals(vector<int>& arr, int k)
{
    //Code here
    int ans1 = 0 ,n = arr.size();
    if(n==1)
        return 0;
    sort(arr.begin(),arr.end());
    int ptr1 = 0,ptr2 = 1;
    while (ptr2<n)
    {
        if(arr[ptr2]-arr[ptr1]<=k||ptr2<=ptr1) 
        {
            ptr2++;
            ans1 = max(ans1,ptr2-ptr1);
        }
        else 
            ptr1++;
    }
    
    return n-ans1 ;

}








