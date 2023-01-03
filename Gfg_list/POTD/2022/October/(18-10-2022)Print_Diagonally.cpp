// https://practice.geeksforgeeks.org/problems/print-diagonally4331/1






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


vector<int> downwardDigonal(int N, vector<vector<int>> A)
{
    // Your code goes here
    vector<int> ans1 ;
    int limit = 2*N-2;

    for (int len1 = 0; len1 <=limit; len1++)
        for (int i1 = 0; i1 < N; i1++)
            if(len1-i1>=0 && len1-i1<N)
                ans1.push_back(A[i1][len1-i1]);


    return ans1 ;
}



