
// https://practice.geeksforgeeks.org/problems/count-of-subarrays5922/1




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






ll countSubarray(int arr[], int n, int k) 
{
    // code here
	    int ptr1 =0 ,ptr2 = 0 ;
        ll ans1 = 0;
        while(ptr1<n)
        {
            if(arr[ptr1]<=k)
            {
                ptr2 = ptr1;
                while(ptr2<n && arr[ptr2]<=k)
                    ptr2++;
                int temp = ptr2-ptr1 ;
                ans1+=(((temp+1)*temp)/2);
                ptr1 = ptr2 ;
            }
            else 
                ptr1++ ;
        }
        ll ans2 = n;
        ans2 = (((ans2+1)*ans2)/2);
        return ans2-ans1;
}













