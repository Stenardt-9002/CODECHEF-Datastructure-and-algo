// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day11/problem/minimize-the-heights3351







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




int getMinDiff(int arr[], int n, int k) 
{
    // code here
    sort(arr,arr+n);
    int min_val = arr[0];
    int max_val = arr[n-1];
    int ans1 = max_val -min_val;
    for (int i1 = 1; i1 < n; i1++)
    {
        if(arr[i1]-k<0) 
            continue ;
        min_val = min(arr[0]+k , arr[i1]-k);
        max_val = max(arr[n-1]-k , arr[i1-1]+k);
        ans1 = min(ans1,abs(max_val-min_val));
    }
    return ans1 ;
}



