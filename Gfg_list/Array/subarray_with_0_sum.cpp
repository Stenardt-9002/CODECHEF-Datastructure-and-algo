// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1/?page=3&curated[]=2&sortBy=submissions

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



bool subArrayExists(int arr[], int n)
{
    //Your code here
    vector<int> dp1(n,0);
    dp1[0] = arr[0];
    if(arr[0]==0)
        return true ;
    for(int i1=1 ; i1<n ; i1++)
    {
        dp1[i1] = arr[i1]+dp1[i1-1];
        if(arr[i1]==0 || dp1[i1]==0)
            return true ;
    }

    set<int> nmap ;
    for(int i1 = 0 ;i1 < n ;i1++)
    {
        if(nmap.find(dp1[i1])!=nmap.end())
            return true ;
        nmap.insert(dp1[i1]);
    }

    return false ;
}
