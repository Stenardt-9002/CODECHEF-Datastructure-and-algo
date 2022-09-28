// https://practice.geeksforgeeks.org/problems/queries-on-a-matrix0443/1




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


vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
    // Code here
    vector<vector<int>>dummy(n,vector<int>(n,0));
    for(auto vec : Queries)
    {
        int row1 = vec[0];
        int col1 = vec[1];
        int row2 = vec[2];
        int col2 = vec[3];
        for (int i1 = col1;    i1 <= col2; i1++)
        {
            dummy[row1][i1]++ ;
            if(row2!=n-1)
                dummy[row2+1][i1]-- ;
        }
        

    }

    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 1; j1 < n; j1++)
            dummy[j1][i1]+=dummy[j1-1][i1];

    return dummy ;    
}







int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n ;//, target;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        // cout<<swapBitGame(n)<<endl;
    }
    return 0 ;
}

