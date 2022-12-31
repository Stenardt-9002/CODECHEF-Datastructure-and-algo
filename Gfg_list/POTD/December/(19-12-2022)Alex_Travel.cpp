// https://practice.geeksforgeeks.org/problems/alex-travelling/1













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
    int minimumCost(vector<vector<int>>& flights, int n, int k) 
    {
        // code here
        set<pair<int,int>>heap ;
        vector<int> dist(n , INT_MAX);
        dist[k-1] = 0 ;
        heap.insert({0 , k-1});

        vector<vector<vector<int>>> graph(n) ;
        for (auto mem: flights)
        {
            int src = mem[0]-1;
            int des = mem[1]-1 ;
            int weight = mem[2];
            graph[src].push_back({des,weight});
        }
        

        while (!heap.empty())
        {
            pair<int,int> top = *(heap.begin());
            heap.erase(heap.begin());

            int src = top.second ;
            for (auto child : graph[src])
            {
                int des = child[0];
                int weight = child[1];
                if (dist[des]>dist[src]+weight)
                {
                    if(dist[des]!=INT_MAX)
                        heap.erase(heap.find({dist[des],des}));

                    dist[des] = dist[src]+weight;
                    heap.insert({dist[des],des});
                }
            }
        }
        int ans = INT_MIN ;
        for (int i = 0; i < n; i++)
            ans = max(ans , dist[i]);
        
        if(ans==INT_MAX)
            return -1 ;
        return ans ;
    }
};