// https://practice.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1?page=1&difficulty[]=2&status[]=unsolved&category[]=Binary%20Search&sortBy=submissions








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

const long long int mod2 =  1e18 ;



class Solution{
    public:
    int KthSmallest(int m, int n, int k) 
    {
        //Write your code here
        int low = 1 , high = m*n ;
        int ans = high ; 
        while(low<=high)
        {
            int mod = low+(high-low)/2;
            int cnt = 0;
            for(int i = 1; i<=m ;i++)
                cnt+=min(n , mod/i);
            if(cnt>=k)
            {
                ans = mod ; 
                high = mod-1 ;
            }
            else 
                low = mod+1 ;
        }
        return ans ;
    }
};























