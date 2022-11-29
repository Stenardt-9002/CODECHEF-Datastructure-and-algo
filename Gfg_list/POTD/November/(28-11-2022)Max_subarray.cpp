// https://practice.geeksforgeeks.org/problems/maximum-sub-array5443/1













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





vector<int> findSubarray(int a[], int n) 
{
    // code here
    vector<int> ans1,curr;
    int max_sum = INT_MIN ;
    int cur_sum = 0 ;
    int start_index = 0 , length = 0;
    for (int i = 0; i < n; i++)
    {
        start_index = i ;
        if(a[i]<0)
            continue ;
        while(i<n && a[i]>=0)
        {
            cur_sum+=a[i];
            curr.push_back(a[i]);
            i++ ;
        }

        if(max_sum<cur_sum || (max_sum == cur_sum && length<i-start_index))
        {
            max_sum = cur_sum ;
            length = i-start_index ;
            ans1 = curr ;
        }
        cur_sum = 0;
        curr.clear();
    }
    if(ans1.size()==0)
        return {-1};
    return ans1 ;
}
    




















