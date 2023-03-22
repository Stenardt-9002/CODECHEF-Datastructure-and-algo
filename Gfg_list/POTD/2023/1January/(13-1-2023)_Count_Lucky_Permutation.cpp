
// https://practice.geeksforgeeks.org/problems/e9e2da3de3eb35679ca7e17b752ae877635f1a26/1










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


















#define ll long long
long long int dp1[(1<<15)+1][15];

class Solution {


  public:
    long long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        // Code here
        // vector<vector<ll>>adj(N);
        unordered_set<int>connection[N];
        for(auto a : graph)
        {
            connection[a[0]-1].insert(a[1]-1);
            connection[a[1]-1].insert(a[0]-1);
        }
        vector<ll> pos(N,0) , ppos(N,0);
        for(ll i = 0 ; i<N;i++)
            pos[--arr[i]] |= 1<<i;
        for(ll i = 0 ; i<N;i++)
            for(ll child : connection[arr[i]])
            ppos[i] |= pos[child];
        
        for(ll i = 0 ; i<(1<<N);i++)
            for(ll child =0 ;child<N ;child++)
            dp1[i][child] = i ?0:1 ;
        for(ll i = 1 ; i<(1<<N)-1;i++)
            for(ll j =0 ;j<N ;j++)
                if(!(i&(1<<j)))
                {
                    ll k = i&ppos[j];
                    while (k)
                    {
                        ll p = log2(k);
                        dp1[i][j] += dp1[i^(1<<p)][p];
                        k^=(1<<p);
                    }
                }
        ll res = 0 ,i = (1<<N)-1 ;
        for(ll j = 0 ;j<N;j++)
        {
            dp1[i][j]+=dp1[i^(1<<j)][j];
            res+=dp1[i][j];
        }
        return res;
    }
    

};


