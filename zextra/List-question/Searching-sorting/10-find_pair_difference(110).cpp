// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    int i1 = 0 ,j1 = 1; 
    while(i1<size&&j1<size )
    {
        // cout<<" "<<arr[j1]-arr[i1]<<" ";
        if(i1!=j1 && abs(arr[j1]-arr[i1])==n )
            return true ;
        else if(arr[j1]-arr[i1]>n)
            i1++ ;
        else 
            j1++;
    }
    return false ;
}



int main(int argc, char const *argv[])
{
    int n ; cin>>n ;
    int *arr1 = new int[n];

    for (int i1 = 0; i1 < n; i1++)
        cin>>arr1[i1];
    
    cout<<endl<<findPair(arr1,n,78);
    delete []arr1 ;
    return 0;
}

