// https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/0/?track=amazon-arrays&batchId=192

#include <bits/stdc++.h>
// #include<ext/pbcumu_valds/tree_policy.hpp>
// #include<ext/pb_ds/assoc_container.hpp>


using namespace std;
// using namespace __gnu_pbds ;
typedef  long long int ll1d;




int normal_kadane(int arr[], int n)
{
    int max_sum=arr[0] , cur_sum=arr[0] ;
    for(int i1 = 1; i1<n;i1++)
    {
      cur_sum = max(arr[i1],cur_sum+arr[i1]);
      max_sum = max(max_sum,cur_sum);
    }
    // your code here
    return max_sum ;
}

int circularSubarraySum(int arr[], int num)
{
    int max_normal_kade = normal_kadane(arr,num);
    if(max_normal_kade<0)
      return max_normal_kade;

    int max_wrap = 0 ,i1 ;
    for(i1=0;i1<num;i1++)
    {
      max_wrap += arr[i1];
      arr[i1]*=-1 ;
    }

    max_wrap+=normal_kadane(arr,num);

    return (max_wrap>max_normal_kade)? max_wrap : max_normal_kade ;
}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int *arr1 = new int[n];
    for(int i1=0;i1<n;i1++)
      cin>>arr1[i1];

    cout<<endl<<circularSubarraySum(arr1,n);

    delete[] arr1;
    return 0;
}
