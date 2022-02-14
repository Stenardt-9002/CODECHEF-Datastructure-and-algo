#include "bits/stdc++.h"

using namespace std;



int countSubset(int arr[],int curr , int sum,int &count,int **dp1)
{
    if (curr== 0 && sum != 0 && dp1[0][sum])
    {
        if (arr[curr] == sum)
              return count;
    }
    if (curr == 0 && sum == 0)
    {
        return count ;
    }
    if (dp1[count-1][sum])
    {
        count = countSubset(arr, curr-1, sum, count,dp1);
    }
    if (sum >= arr[curr] && dp1[curr-1][sum-arr[curr]])
    {
        count = countSubset(arr, curr-1, sum-arr[curr], count,dp1)+1;
        // printSubsetsRec(arr, i-1, sum-arr[i], p);
    }



}


bool isSubsetSum(int n, int arr[], int sum)
{

             int dp1[n][sum+1];
            
            
            for (int i1 = 0; i1 <n; i1++)
            {
                for (int j1 = 0; j1 <= sum; j1++)
                {
                    dp1[i1][j1] = 0;
                }
            }
            // dp[i,j] i: sum j: element 
        
            for (int j1 = 0; j1 < n; j1++){  dp1[j1][arr[j1]] = 1;            }
        
            for (int i1 = 1; i1 <n; i1++)
            {
                for (int j1 = 0; j1 <= sum; j1++)
                {
                    if(j1>=arr[i1]  )
                    {
                        dp1[i1][j1] = (dp1[i1-1][j1]||dp1[i1-1][j1-arr[i1]] );
                    }
                    else 
                    {
                        dp1[i1][j1] = dp1[i1-1][j1];
                    }
                }
            }
        

            return dp1[n-1][sum];

}