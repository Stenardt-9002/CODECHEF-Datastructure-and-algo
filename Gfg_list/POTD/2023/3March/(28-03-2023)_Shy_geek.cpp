// https://practice.geeksforgeeks.org/problems/59dfb26eb6c659e6e5f60869ac335f450f97165a/1














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










class Solution{
    public:
    
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        
        // 'shop'.
        unordered_map<int, int> hash ;
        long long int ans = 0 ;
        int low = 0 , high = n-1 ; 
        int count = 50 ;
        while(k>0 && count>0)
        {
            long long int cure = -1 ;
            
            while(low<=high && count>0)
            {
                int mid = low+(high-low)/2;
                if(!hash.count(mid))
                {
                    hash[mid] = shop.get(mid);
                    --count ;
                }
                
                int get_val = hash[mid];
                if(get_val<=k)
                {
                    cure = mid ;
                    low = mid+1 ;
                }
                else 
                    high = mid-1 ;
                
            }
            if(cure==-1 || hash[cure]>k)
                break ;
            long long int val = hash[cure];
            long long int temp = (long long int)(k/val);
            ans+=temp ;
            k = k%val ;
            
                
            low = 0 ;
        }
        
        // return this->shop.get(n-1);
        
        return ans ; 
    }
};




















