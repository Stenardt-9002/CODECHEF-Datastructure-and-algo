
// https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1










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
#define MAX 1000



vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
//Your code here
    unordered_map<string,int> map1 ;
    for(int i = 0;i<row;++i)
    {
        string cur = "" ;
        for(int j = 0 ; j<col ; ++j)
            cur+=to_string(M[i][j]+'0');
        if(map1.find(cur)==map1.end())
            map1[cur] = i;
    }
    vector<vector<int>>ans1 ;
    set<int>index ;
    for(auto key:map1)
        index.insert(key.second);
    for(auto key:index)
    {
        vector<int> temp1 ;
        for(int ele = 0 ;ele<col ; ele++)
            temp1.push_back(M[key][ele]);
        ans1.push_back(temp1);
    }
    return ans1 ;
}