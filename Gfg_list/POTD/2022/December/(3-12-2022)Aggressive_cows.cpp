// # https://practice.geeksforgeeks.org/problems/aggressive-cows/1







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


bool allowed(vector<int>stalls , int n , int k , int distance)
{
    int i = 0 , j= 1;
    k-- ;
    while (i<n && j<n && k>0)
    {
        if(stalls[j]-stalls[i]<distance)
            j++ ;
        else 
        {
            k-- ;
            i = j ;
        }
    }
    return k<=0 ;
}




int solve(int n, int k, vector<int> &stalls) 
{
    int l = 1 , r = 1e9 ;
    int ans = -1 ;
    sort(stalls.begin() ,stalls.end());
    while (l<=r)
    {
        int mid = l+(r-l)/2 ;
        if(allowed(stalls , n , k , mid))
        {
            ans = mid ;
            l = mid+1 ;
        }
        else 
            r = mid-1 ;
    }
    return ans ;
    // Write your code here
}






int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {
        int n , k;
        cin>>n >> k ;
        vector<int>arr(n,0);
        for (int i = 0; i < n; i++)
            cin>>arr[i];
        
        cout<<solve(n , k , arr)<<endl;
    }
    

    return 0;
}




