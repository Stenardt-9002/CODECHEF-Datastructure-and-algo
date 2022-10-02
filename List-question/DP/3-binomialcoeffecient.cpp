
// https://practice.geeksforgeeks.org/problems/ncr1019/1
#include "bits/stdc++.h"
const unsigned int D1 = 1000000007;
using namespace std;
    int nCr(int n, int r)
    {
        if(n<r){return 0;}
        const unsigned int D1 = 1000000007;
        unsigned long long int dp1[n+1][r+1];

        for (int i1 = 0; i1 <=n; i1++)
        {
            for (int j1 = 0; j1 <=r; j1++)
            {dp1[i1][j1] = 1;}
        }
        for (int i = 1; i < n+1; i++)
        {
            for (int j1 = 1; j1 <min(i,r+1); j1++)
            {
                dp1[i][j1] = dp1[i-1][j1-1]+dp1[i-1][j1];
                dp1[i][j1] = dp1[i][j1]%D1;
            }
        }
        return (dp1[n][r])%D1 ;
    }


int main(int argc, char const *argv[])
{
    int n,k;cin>>n>>k;
    cout<<nCr(n,k);
    return 0;
}




