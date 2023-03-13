// https://practice.geeksforgeeks.org/problems/a3493283697b7b69573a840f371a55ccd9332bb0/1









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

class Solution {
  public:
    void dfs(int u,int p,vector<int> adj[],vector<vector<long long>> &ans,vector<int> &a,vector<bool> &lef)
    {
		bool islef = 1;
        for(int v:adj[u])
        {
            if(p!=v)
            {
				islef = 0;
                ans[v][0] = max({ans[v][0],ans[u][1]+a[v]});
                ans[v][1] = max({ans[v][1],ans[u][0]-a[v]});
                dfs(v,u,adj,ans,a,lef);
            }
        }
        lef[u] = islef;
    }
    long long bestNode(int n, vector<int> &A, vector<int> &P) {
        // code here
        vector<vector<long long>> v(n ,vector<long long>(2,-1e18));
        for(int i = 0; i<n; i++)
        {
            v[i][0] = A[i];
        }
        
        for(int &i:P)i--;
        vector<int> adj[n];
        for(int i = 1; i<n; i++)
        {
            adj[i].push_back(P[i]);
            adj[P[i]].push_back(i);
        }
       
        vector<bool> lef(n,0);
        dfs(0,-1,adj,v,A,lef);
        long long ans = -1e18;
        for(int i = 0; i<n; i++)
        {
			if(lef[i])
            ans = max({ans,v[i][0],v[i][1]});
        }
        return ans;
    }
};



class Solution{
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) 
    {
        // code here
        vector<vector<ll>> dp1(N , vector<long long>(2,INT_MIN));
        // 0 means postive score 1 means negative score 
        int i = 0;
        for(auto s : A)
            dp1[i++][0] = s;
        for(int i = 0 ;i<N;++i)
            P[i]--;

        
        for (int i = 1; i < N; i++)
        {
            ok[i] = !ok[P[i]-1];
            int cur_val = A[P[i]-1];
            if(ok[i])
            cur_val += A[i];
            else 
            cur_val -= A[i];

            if(cur_val>A[i])
                A[i]=cur_val ;
            else 
                ok[i] = true ;
        }
        
        return *max_element(A.begin(),A.end()) ;
    }
};






