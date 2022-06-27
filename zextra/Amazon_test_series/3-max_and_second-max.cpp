// https://practice.geeksforgeeks.org/problems/max-and-second-max/0/?track=amazon-arrays&batchId=192

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max1 = INT_MIN, max2= INT_MIN;

    /*********************************
     * Your code here
     * This function should return a
     * vector with first element as
     * max and second element as
     * second max
     * *******************************/
     int n=sizeOfArray;
     if(n==0)
       return {-1,-1};
     if(n==1)
       return {arr[0],-1};

     max1 = max(arr[0],arr[1]);
     max2 = min(arr[0],arr[1]);
     if(max1==max2)
         max2 = -1;

     for(int i1 = 2; i1<n ; i1++)
     {
         if(arr[i1]>max1)
         {
           max2 = max1 ;
           max1 = arr[i1];
         }
         else if(arr[i1]>max2 && max1!=arr[i1])
           max2 = arr[i1];

      }
     return {max1,max2};
}
