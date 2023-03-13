// https://practice.geeksforgeeks.org/problems/899540d741547e2d75d1c5c03a4161ab53affd13/1









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






bool is_OK(vector<int> a,int n ,int k,int w,ll mid)
{
    vector<ll> dp(n,0);
    //lazy propagation
    if(a[0]<mid)
    {
        dp[0] = mid-a[0];
        k -= (mid-a[0]);
    }
    if(k<0)
        return false ;

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i-1];
        ll actualh = a[i];
        if(i>=w)
            actualh+=(dp[i]-dp[i-w]);
        else 
            actualh+=(dp[i]);

        if(actualh<mid)
        {
            dp[i]+=(mid-actualh);
            k -= (mid-actualh);
        }
        if(k<0)
            return false ;
    }
    return true ;
    

}








class Solution
{
    public:
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            // code here
            long long int ans = 0 ;
            ll low = *min_element(a.begin(),a.end());
            ll hgh = INT_MAX ;
            while(low<=hgh)
            {
                ll mid = low+(hgh-low)/2;
                if(is_OK(a,n ,k,w,mid))
                {
                    ans = mid ;
                    low = mid+1 ;
                }
                else 
                    hgh = mid-1;

            }
            return ans ;
        }
};
















