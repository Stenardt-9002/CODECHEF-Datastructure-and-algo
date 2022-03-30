#include "bits/stdc++.h"

using namespace std;


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

            for (int j1 = 0; j1 < n; j1++)
            {                dp1[j1][arr[j1]] = 1;            }

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


int main(int argc, char const *argv[])
{
    int n;
    cin>>n ;


    int *arr1 = new int[n] ;
    int sum1 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr1[i1] ;
    }
    cin>>sum1 ;

    cout<<isSubsetSum(n,arr1,sum1);
    return 0;
}
