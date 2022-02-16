
#include "bits/stdc++.h"

using namespace std;

    int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
    {
        int m = A.length();
        int n = B.length();
        int o = C.length();
        int dp1[m+1][n+1][o+1]
        for (int i1 = 0; i1 < m+1; i1++)
        {
               for (int j1 = 0; j1 < n+1; j1++)
                {
                    for (int k1 = 0; k1 < o+1; k1++)
                    {
                        dp1[i1][j1][k1] = 0;
                    }
                    
                }
                
        }
        

        for (int i1 = 0; i1 < m+1; i1++)
        {
            for (int j1 = 0; j1 < n+1; j1++)
            {
                for (int k1 = 0; k1 < o+1; k1++)
                {
                    if(A[i1-1]==B[j1-1]&&B[j1-1]==C[k1-1])
                    {                        
                        dp1[i1][j1][k1] = 1+dp1[i1-1][j1-1][k1-1];
                    }
                    else
                    {
                        dp1[i1][j1][k1] = max({dp1[i1-1][j1][k1],dp1[i1][j1-1][k1],dp1[i1][j1][k1-1]});
                    }
                    
                }
                
            }
                
        }
        

        // for (int i1 = 0; i1 < m+1; i1++)
        // {
        //     dp1[i1][0] = 0;
        // }
        

        // for (int i1 = 0; i1 < n+1; i1++)
        // {
        //     dp1[0][i1] = 0;
        // }
        
        // for (int i1 = 1; i1 < m+1; i1++)
        // {
        //     for (int j1 = 1; j1 < n+1; j1++)
        //     {
        //         if (s1[i1-1]==s2[j1-1])
        //         {
        //             dp1[i1][j1] = 1+dp1[i1-1][j1-1];
        //         }
        //         else
        //         {
        //             dp1[i1][j1] = max(dp1[i1][j1-1],dp1[i1-1][j1]);
        //         }
                
                
        //     }
            
        // }
        // return dp1[m][n];

    }

