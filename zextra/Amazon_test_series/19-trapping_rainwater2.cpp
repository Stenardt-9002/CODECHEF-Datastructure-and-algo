// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/0/?track=amazon-arrays&batchId=192

#include <bits/stdc++.h>
#include<ext/pbcumu_valds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


long long trappingWater(int arr[], int n)
{
  int n= arr.length();
  int left = 0 , right = n-1 ;
  int res = 0 ;
  int maxleft = 0 , maxright = 0 ;

  while (left<=right)
  {
    if(arr[left]<=arr[right])
    {
      if(arr[left]>=maxleft )
        maxleft = arr[left];
      else
        res+=maxleft-arr[left];

      left++ ;
    }

    else
    {
      if(arr[right]>=maxright)
        maxright = arr[right];
      else
        res+=maxright-arr[right];

      right-- ;
    }

  }
  return res ;
}


int trap(vector<int>& height)
{
  int n= height.length();
  int left = 0 , right = n-1 ;
  int res = 0 ;
  int maxleft = 0 , maxright = 0 ;

  while (left<=right)
  {
    if(height[left]<=height[right])
    {
      if(height[left]>=maxleft )
        maxleft = height[left];
      else
        res+=maxleft-height[left];

      left++ ;
    }

    else
    {
      if(height[right]>=maxright)
        maxright = height[right];
      else
        res+=maxright-height[right];

      right-- ;
    }

  }
  return res ;
}
