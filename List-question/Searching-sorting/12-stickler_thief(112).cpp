#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


// int util_fucn(int arr[], int n , vector<int>&dp1)
// {
//     if(n<0)
//         return 0 ;
//     if(n==0)
//         return arr[0];
//     if(dp1[n]!=-1)
//         return dp1[n];
//     int pick = arr[n]+util_fucn(arr,n-2,dp1);
//     int notpick = util_fucn(arr,n-1,dp1);
//     return dp1[n] = max(pick,notpick);
// }


// int FindMaxSum(int arr[], int n)
// {
//     // Your code here
//     vector<int> dp1(n+1,-1);
//     return util_fucn(arr,n-1,dp1);

// }





int FindMaxSum(int arr[], int n)
{
    // Your code here
    if(n==0)
        return 0 ;

    if(n==1)
        return arr[0] ;
    if(n==2)
        return max(arr[0],arr[1]);
    vector<int> dp1(n,-1);

    dp1[0] = arr[0];
    dp1[1] = max(arr[0],arr[1]);
    for (int i1 = 2; i1 < n; i1++)
        dp1[i1] = max(dp1[i1-1],dp1[i1-2]+arr[i1]);

    return dp1[n-1];
}


