// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1/




#include "bits/stdc++.h"

using namespace std;


int longestPalinSubseq(string A) 
{
            int n = A.length();
            int dp1[n][n] ; //dp[i,j] = j-i length of subsequence that is pallindrome 
        
            for (int i1 = 0; i1 < n; i1++)
            {

                dp1[i1][i1] = 1;
                if(i1<n-1)
                {
                    if(A[i1]==A[i1+1])
                    dp1[i1][i1+1] = 2;
                    else
                    dp1[i1][i1+1] = 1;
                }
            }
            
            int j1 ; 
            for (int l1en = 3; l1en <=n; l1en++)
            {
        
                for (int i1 = 0; i1 < n-l1en+1; i1++)
                {
                    j1 = i1+l1en-1 ;
                    if (A[i1]==A[j1])
                    {
                        dp1[i1][j1] = dp1[i1+1][j1-1]+2 ;// length from subsequence[i1+1:j1-1]+2 include i1,j1
                    }
                    else
                    {
                        dp1[i1][j1] = max(dp1[i1+1][j1],dp1[i1][j1-1]);
                    }
                    
                    
                }
                
            }
            
        
            return dp1[0][n-1];
    

}











