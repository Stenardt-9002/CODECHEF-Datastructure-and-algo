
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1


#include "bits/stdc++.h"

using namespace std;

    int longestSubsequence(int n, int a[])
    {
       vector<int> dp1(n);
       for(int i1=0;i1<n;i1++)
        dp1[i1] =1;
       
       
       for(int i1=1;i1<n;i1++)
       {
        for(int j1=0;j1<i1;j1++)    
            if(a[j1]<a[i1])
                dp1[i1] = max(dp1[i1],dp1[j1]+1);
       }
       return *max_element(dp1.begin(),dp1.end()) ;
    }

