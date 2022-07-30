// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
bool func_allow(int *arr1 , int n ,int k,long long int current_tme)
{
    int current_sum =0,i1=0,j1=0; 
    while(i1<n&&j1<k)
        if(arr1[i1]+current_sum<=current_tme)
            current_sum += arr1[i1++] ;

        else 
            j1++ , current_sum = 0 ;


    if(i1!=n)
        return false ;
    return true ;
    
}

long long minTime(int arr[], int n, int k)
{
    // code here
    // return minimum time
    long long int high = arr[0];
    for (long long int i1 = 1; i1 < n; i1++)
        high+=arr[i1]    ;
    long long int low = *max_element(arr,arr+n);

    if(n<=k)
        return low ;

    long long int ans1 = high ;
    while (low<=high)
    {
        long long int mid = (low+high)>>1 ;

        if(func_allow(arr , n,k,mid ))
        {
            ans1 = mid ;
            high = mid -1 ;
        }
        else 
            low = mid+1 ;
    }
    return ans1 ;

}


int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    int n , m ;
    cin>>n>>m ;//m cows n holes
    int *arr1 = new int[n];
    for ( int i1 = 0; i1 < n; i1++)
        cin>>arr1[i1]    ;

    cout<<endl<<minTime(arr1,n,m);
    // for (int i1 = 0; i1 < n; i1++)
    //     cout<<" "<<arr1[i1];
    
    // cout<<endl<<func_allow(arr1,n,m,35);

    delete[] arr1 ;
    return 0;
}




