#include "bits/stdc++.h"

using namespace std;
    int equalPartition(int N, int arr[])
    {
        int sum1 = 0;
        for (int i1 = 0; i1 < N; i1++)
        {
            sum1+=arr[i1];
        }
        
        // cout<<sum1<<endl;
        int n = N;
        if(sum1%2!=0)
        {
            return 0;
        }
        else
        {
            sum1 = sum1/2;
        }
        
        int dp1[n][sum1+1];


        for (int i1 = 0; i1 < n; i1++)
        {
            for (int j1 = 0; j1 < sum1+1; j1++)
            {
                dp1[i1][j1] = 0;
            }
            
        }
        for (int i1 = 0; i1 < n; i1++)
        {
            dp1[i1][arr[i1]] = 1;//single element
        }
        for (int i1 = 1; i1 < n; i1++)
        {
            for (int j1 = 0; j1 < sum1+1; j1++)
            {
                if (j1>=arr[i1])
                {
                    dp1[i1][j1] = dp1[i1-1][j1]||dp1[i1-1][j1-arr[i1]];    
                }
                else
                {
                    dp1[i1][j1] = dp1[i1-1][j1];    
                }                
            }
            
        }
        
        
        return dp1[n-1][sum1];

    }





int main(int argc, char const *argv[])
{
    int n;
    cin>>n ;

    int *wt = new int[n] ;

    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>wt[i1] ;
    }
    

    cout<<equalPartition(n,wt);




    delete []wt ;
    return 0;
}








