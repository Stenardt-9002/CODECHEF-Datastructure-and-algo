// https://practice.geeksforgeeks.org/problems/equivalent-sub-arrays3731/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

int countDistinctSubarray(int arr[], int n)
{
    //code here.
    unordered_map<int,int> vis_ted ;
    for(int i1 = 0;i1<n;++i1)
      vis_ted[arr[i1]] = 1;

    int hasmapsize = vis_ted.size();
    vis_ted.clear();
    int ans1 = 0 ,right = 0 , window = 0 ;

    for(int left = 0 ; left<n ;left++)
    {
      while(right<n && window<hasmapsize)
      {
        ++vis_ted[arr[right]];
        if(vis_ted[arr[right]]==1)
          ++window ;

        ++right ;
      }
      if(window==hasmapsize)
        ans1+=(n-right+1);

      --vis_ted[arr[left]] ;

      if(vis_ted[arr[left]]==0)
        window--;
    }

    return ans1 ;

}
