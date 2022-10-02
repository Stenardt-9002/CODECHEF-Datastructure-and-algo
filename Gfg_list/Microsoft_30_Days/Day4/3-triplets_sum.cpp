// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day4/problem/triplet-sum-in-array-1587115621





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



bool find3Numbers(int A[], int n, int X)
{
    //Your Code Here
    sort(A,A+n);
    for (int i1 = 0; i1 < n; i1++)
    {
        int j1 = i1+1 ,k1 = n-1 ;
        int target = X-A[i1];
        while(j1<k1)
        {
            if(A[j1]+A[k1]>target)
                k1-- ;
            else if(A[j1]+A[k1]<target)
                j1++ ;
            else 
                return true ;
        }
    }
    return false ;
}


