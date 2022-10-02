
// https://practice.geeksforgeeks.org/batch-problems/longest-subarray-with-sum-divisible-by-k1259/0/?track=microsoft-29days-day1&batchId=636




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






int longSubarrWthSumDivByK(int arr[], int n, int k)
{
    // Complete the function
    unordered_map<int , int > map1 ; //remainder  , first index
    ll sum1 = 0 ;
    int ans1 = 0 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        sum1+=arr[i1];
        int rem = sum1%k ;
        if(rem == 0)
            ans1 = max(ans1 , i1+1);
        
        if(rem<0)
            rem+=k ;



        if(map1.find(rem)==map1.end())//no found
            map1[rem] = i1 ;
        else 
            ans1 = max(ans1 , i1-map1[rem]);

    }
    
    return ans1 ;
}




