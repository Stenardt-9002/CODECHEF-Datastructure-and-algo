// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day2/problem/zero-sum-subarrays1825    
    







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);






// ll findSubarray(vector<ll> arr, int n ) 
// {
//     //code here
//     unordered_map<ll,vector<ll>> map ;
//     ll su1m = 0 ,ans1 = 0;

//     for (int i2 = 0; i2 < n; i2++)
//     {
//         su1m+=arr[i2];

//         if(su1m==0)
//             ans1++ ;

//         if(map.find(su1m)!=map.end())
//         {
//             vector<ll>des = map[su1m];
//             for(auto it:des)
//                 ans1++ ;
//         }

//         map[su1m].push_back(i2);
//     }
    
//     return ans1 ;



// }




ll findSubarray(vector<ll> arr, int n ) 
{
    //code here
    unordered_map<ll,ll> map ;
    ll su1m = 0 ,ans1 = 0;

    for (int i2 = 0; i2 < n; i2++)
    {
        su1m+=arr[i2];
        if(su1m==0)
            ans1++ ;

        if(map.find(su1m)!=map.end())
            ans1+=map[su1m];

        map[su1m]++;
    }
    
    return ans1 ;
}