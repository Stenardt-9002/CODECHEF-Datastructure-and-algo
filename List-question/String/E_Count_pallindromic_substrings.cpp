
  
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);



int countSubstrings(string S) {
        

    int n = S.length();
    vector<vector<bool>>dp1(n,vector<bool>(n,false));
    for (int i1 = 0; i1 < n; i1++)
        dp1[i1][i1]=true;
    for (int i1 = 0; i1 < n-1; i1++)
        if(S[i1]==S[i1+1])
            dp1[i1][i1+1]=true;

    for (int len = 2; len < n; len++)
    {
        for (int star = 0; star < n-len; star++)
        {
            int j1 = star+len;
            if(dp1[star+1][j1-1]&&(S[star]==S[j1]))
                dp1[star][j1]=true ;
        }
    }
    int cunt1 = 0 ;
    for (int j1 = 0; j1 < n; j1++)
        for (int i1 = 0; i1 <= j1; i1++)
            if(dp1[i1][j1])
                cunt1++;
    return cunt1 ;
}