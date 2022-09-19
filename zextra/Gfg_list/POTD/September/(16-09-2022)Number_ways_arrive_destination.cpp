// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1










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




int countPaths(int n, vector<vector<int>>& roads) 
{
    // code here

    vector<pair<int,int>> *grahp1 = new vector<pair<int,int>>[n];
    for(auto edges : roads)
        grahp1[edges[0]].push_back({edges[1] ,edges[2]}) ,grahp1[edges[1]].push_back({edges[0] ,edges[2]}) ;

    int ans1 = 0 ;
    priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> >pq1 ;
    vector<int> shrtdes(n,INT_MAX);
    shrtdes[0] = 0 ;

    pq1.push({0,0});

    while (!pq1.empty())
    {
        int dis = pq1.top().first ;
        int node = pq1.top().second ;

        pq1.pop();

        for(auto child : grahp1[node])
        {
            int childnode = child.first ;
            int nextdis = child.second ;
            if(childnode==n-1)//des
            {
                if(shrtdes[n-1]== dis+nextdis)
                    ans1 = (ans1+1ll)%MOD1;
                else if(shrtdes[n-1]> dis+nextdis)
                {
                    shrtdes[n-1] = dis+nextdis;
                    ans1 = 1 ; //reset 
                }
            }
            else if(shrtdes[childnode]>=dis+nextdis)
            {
                shrtdes[childnode] = shrtdes[node]+nextdis;
                pq1.push({shrtdes[childnode] , childnode});
            }
        }
    }
    return ans1 ;    


}