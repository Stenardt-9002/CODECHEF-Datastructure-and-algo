// https://practice.geeksforgeeks.org/problems/brain-game1742/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


long long int minSum(int arr[], int n)
{
    // Your code goes here
    if(n==1)
        return arr[0];
    
    sort(arr,arr+n,greater<int>());
    long long int asum =0 ;
    long long int piwe = 1 ;
    for (int i1 = 1; i1 < n; i1+=2)
    {
        asum += (arr[i1])*piwe;
        asum += (arr[i1-1])*piwe;
        piwe*=10 ;
    }
    if(n%2!=0)
        asum += (arr[n-1]*piwe);

    return asum ;
}


int main(int argc, char const *argv[])
{
    int arr[] = {5,7,5};
    // sort(arr,arr+3,greater<int>());
    // cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    cout<<minSum(arr,3)<<endl;
    return 0;
}


