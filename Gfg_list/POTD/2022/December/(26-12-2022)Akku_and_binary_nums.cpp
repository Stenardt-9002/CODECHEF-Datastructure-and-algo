










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




    void precompute()
    {
        // Code Here
    }
    
    long long solve(long long l, long long r)
    {
        // Code Here
        long long ans=0;
        for(int i=0;i<64;i++)
            for(int j=i+1;j<64;j++)
                for(int k=j+1;k<64;k++)
                {
                    long long sar = (long long)pow(2,i) + (long long)pow(2,j) +(long long)pow(2,k);
                    if(sar>=l&&sar<=r)
                        ans++;
                }
        return ans;

    }

};





        




