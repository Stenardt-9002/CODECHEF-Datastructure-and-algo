// https://practice.geeksforgeeks.org/problems/number-of-ways2552/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


long long int arrangeTiles(int N)
{
    // code here
    // vector<ll1d> dp1(N+1,0);
    // dp1[1] = dp1[2] = dp1[3] = 1;
    // dp1[4] = 2;
    // for (int i1 = 4; i1 < =N; i1++)
    //   dp[i1] = dp1[i1-1]+dp1[i1-4];
    //
    // return dp1[N];

    vector<long long> dp1(6,0);
    dp1[1] = 1 ;dp1[2] = 1;dp1[3] = 1;
    dp1[4] = 2;

    if(N<5)
    return dp1[N];

    for (int i1 = 5; i1 <=N; i1++)
      dp1[i1%6] = dp1[(i1-1)%6]+dp1[(i1-4)%6];

    return dp1[N%6];
}
