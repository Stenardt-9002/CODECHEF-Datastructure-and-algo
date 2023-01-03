    
    
    










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








    bool canPair(vector<int> nums, int k) 
    {
        // Code here.
        if(k==1)
            return true ;
        vector<int>remainder1(k,0);
        int n = nums.size();
        for(int i = 0 ; i<n;++i)
            remainder1[nums[i]%k]++;
        
        for(int i = 1 ; i<=k/2;++i)
            if(remainder1[i]!=remainder1[k-i])
                return false ;
        if (!(k%2==0 && remainder1[k/2]%2==0))
            return false ;
            
        if(remainder1[0]%2)
            return false ;
        return true ;
            
    }