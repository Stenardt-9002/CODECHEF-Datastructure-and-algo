// https://practice.geeksforgeeks.org/problems/d894706c496da5c5a4f45b0360c7f4164c516f83/1








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


class Node
{
    
public:
    int data ; vector<Node*>children ;
    Node(int val)
    {
        this->data = val ; 
    }
};





class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        map<int,int> hash ;
        for(auto it : intervals)
        {
            hash[it[0]]++;
            hash[it[1]+1]--;
        }
        int ans = -1 ; 
        int count  = 0 ;
        for(auto it :hash)
        {
            count+=it.second ;
            if(count>=k)
                ans = it.first  ;
            else if(count-it.second>=k)
                ans = it.first -1 ;
        }
        
        return ans ; 
    }
};









