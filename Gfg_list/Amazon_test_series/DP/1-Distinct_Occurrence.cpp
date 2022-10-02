
// https://practice.geeksforgeeks.org/batch-problems/distinct-occurrences/0/?track=amazon-dynamic-programming&batchId=192
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



int subsequenceCount(string S, string T)
{
    //Your code here
    int MOD1 = 1000000007 ;

    int n = S.size() ;
    int m = T.size() ;

    vector<vector<int>> dp1(n+1 , vector<int>(m+1,0)) ;

    // rows are S 


    for (int i1 = 0; i1 <=m; i1++)
       dp1[0][i1] = 0 ; // an empty S will have nbo subsequence 

    for (int i1 = 0; i1 <=n; i1++)
        dp1[i1][0] = 1 ;


    for (int i1 = 1; i1 <=n; i1++)
        for (int j1 = 1; j1 <=m; j1++)
            if(T[j1-1]==S[i1-1])    
                dp1[i1][j1] = (dp1[i1-1][j1]+dp1[i1-1][j1-1])%MOD1 ;
            else //T is not included
                dp1[i1][j1] = (dp1[i1-1][j1])%MOD1 ;
    

    return (dp1[n][m])%MOD1 ;
}

int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 



    return 0 ;
}