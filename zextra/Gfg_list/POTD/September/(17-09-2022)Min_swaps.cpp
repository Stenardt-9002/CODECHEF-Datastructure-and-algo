








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








    int minimumSwaps(int c[],int v[],int n,int k,int b,int T)
    {
            // code here
        int swaps = 0 , curr = 0 ;
        for (int i1 = n-1; i1 >=0; i1--)
        {
            int curr_time = ceil((float)(b-c[i1])/v[i1] );
            if(curr_time>T)
                {curr++ ; continue; }

            swaps+=curr ;
            k-- ;
            if(k==0)
                return swaps ;
        }
        return -1 ;
    }



