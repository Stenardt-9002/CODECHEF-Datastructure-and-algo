
// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#


#include "bits/stdc++.h"

using namespace std;

   int maximumPath(int N, vector<vector<int>> Matrix)
    {
        
        int n = N;
        int dp1[n][n];
        for (int i1 = 0; i1 < n; i1++)
        {
            for (int j1 = 0; j1 < n; j1++)

            dp1[j1][i1] = Matrix[j1][i1];
        }
        

        for (int i1 = 1; i1 <n; i1++)
        {
            int maa1x = INT_MIN ;
            for(int j1 = 0 ;j1<n;j1++)
            {
                    
            if (j1 > 0 && j1 < n - 1)
                dp1[i1][j1] += max({dp1[i1 - 1][j1],dp1[i1 - 1][j1 - 1],dp1[i1 - 1][j1 + 1] });
 
            else if (j1 > 0)
                dp1[i1][j1] += max(dp1[i1 - 1][j1], dp1[i1 - 1][j1 - 1]);
 
            else if (j1 < n - 1)
                dp1[i1][j1] += max(dp1[i1 - 1][j1],dp1[i1 - 1][j1 + 1]);
 
            }
        }




        int max1 = dp1[n-1][0];
        for (int i1 = 1; i1 < n; i1++)
        {
            max1 = max(max1 ,dp1[n-1][i1] ) ;
        }
        

        return max1;
        
    }
int main(int argc, char const *argv[])
{
        int n;
    cin>>n ;

    vector<vector<int>> mstrix(n);
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     mstrix.push_back(a1);
    // }
    
    // int temp1;
    for (int i1 = 0; i1 < n; i1++)
    {
        mstrix[i1] = vector<int>(n);
    }
    
    for (int i1 = 0; i1 < n; i1++)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            cin>>mstrix[i1][j1];
        }
    }
    

    cout<<maximumPath(n,mstrix);

    
    return 0;
}














