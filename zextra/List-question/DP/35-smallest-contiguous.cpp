


#include "bits/stdc++.h"

using namespace std;



int smallestSumSubarr(int arr[], int n)

{
    int min_global = arr[0] ;
    int curr_min = arr[0];

    for (int i1 = 1; i1 < n; i1++)
    {
        curr_min = min(arr[i1],curr_min+arr[i1]);
        min_global = min(min_global,curr_min);
    cout <<endl<<curr_min<<" "<<min_global;

    }
    return min_global;

}

int main(int argc, char const *argv[])
{

    int n;
    cin>>n;
    int arr1[n];
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr1[i1];
    }
    cout<<smallestSumSubarr(arr1,n);

    return 0;
}








