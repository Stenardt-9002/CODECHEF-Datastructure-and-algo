// # https://practice.geeksforgeeks.org/problems/aa0000a5f710ce8d41366b714341eef644ec7b82/1
// 
















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


vector<int> shrtest_path(vector<vector<pair<int,int>>> graph_1 ,int src ,int n )
{
    set<pair<int,int>> s1 ;
    vector<int> ans(n,1e9);
    ans[src] = 0 ;
    s1.insert({0,src});
    while(s1.size())
    {
        int u = s1.begin()->second ;
        s1.erase(s1.begin());
        for(auto itr = graph_1[u].begin();itr!=graph_1[u].end();++itr)
        {
            int child = (*itr).first ;
            int weight = (*itr).second ;
            if(ans[child]>ans[u]+weight)
            {
                if(s1.find({ans[child],child})!=s1.end())
                    s1.erase(s1.find({ans[child],child}));

                ans[child]=ans[u]+weight ;
                s1.insert({ans[child],child});
            }
        }
    }


    return ans ;
}




class Solution {
  public:
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) 
    {
        // code here
        vector<vector<pair<int,int>>> graph_1(n) ; 
        // vector<vector<pair<int,int>>> graph_2(n) ; //curved_edge 
        // vector<map<int,int>> graph_2(n) ; //curved_edge 
        for(auto edge : edges)
        {
            graph_1[edge[0]-1].push_back({edge[1]-1,edge[2]});
            graph_1[edge[1]-1].push_back({edge[0]-1,edge[2]});

            //curved edge
            // graph_2[edge[0]][edge[1]]= edge[3];
            // graph_2[edge[1]][edge[0]]= edge[3];

            // graph_2[edge[0]].push_back({edge[1],edge[3]});
            // graph_2[edge[1]].push_back({edge[0],edge[3]});            
        }
        vector<int>src_vec = shrtest_path(graph_1 , a-1 , n);
        vector<int>des_vec = shrtest_path(graph_1 , b-1 , n);
        int ans = src_vec[b-1];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;
            int wt = edges[i][3];
            ans = min({ans , src_vec[u]+wt +des_vec[v], src_vec[v]+wt +des_vec[u]});
        }
        if(ans>=1e9)
            return -1 ;
        return ans ;

    }
};





