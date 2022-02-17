// https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1



#include "bits/stdc++.h"

using namespace std;

    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        int n = N;
        int sum1 = 0;
        sort(arr,arr+n);
        // for(int i1 = n-1;i1>0;i1--)
        int i1=n-1;
        while(i1>0)
        {
            if(arr[i1]-arr[i1-1]<K)
            {
                sum1+=(arr[i1]+arr[i1-1]);
                i1--;
            }
            i1--;
        }
        
        return sum1;
    }

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n;
    int arr1[n];
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr1[i1];
    }
    cin>>k;
    maxSumPairWithDifferenceLessThanK(arr1,n,k);
    
    return 0;
}



