
// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    sort(arr,arr+n);
    int ans1 = 0 ;
    for (int i1 = n-3; i1 >=0; --i1)
    {
        int j = i1+1 ;
        int k = n-1 ;
        while (j<k)
            if(arr[i1]+arr[j]+arr[k]>=sum)    
                k-- ; 
            else 
                ans1+=(k-j),j++ ;
    }
    return ans1 ; 
}



