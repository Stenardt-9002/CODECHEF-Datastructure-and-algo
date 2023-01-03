// https://practice.geeksforgeeks.org/problems/enemy/1









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



int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
{
    //  code here
    int ans1 = 0 ;
    set<int> row ;
    set<int> col ;
    if(k==0)
        return n*m;

    for(auto pair:enemy)
    {
        row.insert(pair[0]);
        col.insert(pair[1]);
    }
    row.insert(n+1);
    col.insert(m+1);
    int row1 = 0,col1 = 0;
    int max_row = 0 , max_col = 0;
    for (auto r: row)
    {
        max_row = max(max_row,(r-row1-1));
        row1 = r ;
    }
    for (auto c: col)
    {
        max_col = max(max_col,(c-col1-1));
        col1 = c ;
    }
    ans1 = max(ans1,(max_row*max_col));

    return ans1 ;
}
