
// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/





#include "bits/stdc++.h"

using namespace std;

// watch abdul bari video 
    int matrixMultiplication(int N, int arr[])
    {

            int n = N ;
            int dp1[n][n];
            // if [i][i] matrix mul cost 
            for (int i1 = 1; i1 < n; i1++)
            {
                dp1[i1][i1] = 0;
                    
            }
            int j1 ;
        
           for (int k1 = 2; k1 < n; k1++) //length of matrix 
            {    
                for (int i1 = 1; i1 < n-k1+1; i1++)
                {
                    j1 = i1+k1-1; //length of matrix 
                    dp1[i1][j1] = INT_MAX;
                    for (int pass1 = i1; pass1 <j1; pass1++)
                    {
                        dp1[i1][j1] = min(dp1[i1][j1],dp1[i1][pass1]+dp1[pass1+1][j1]+(arr[i1-1]*arr[pass1]*arr[j1]))  ;
                    }
                }        
            }
            
            return dp1[1][n-1];

    }



int main(int argc, char const *argv[])
{
    int n ;
    cin>>n ;

    int arr1[n];
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr1[i1];
    }
    
    return 0;
}






