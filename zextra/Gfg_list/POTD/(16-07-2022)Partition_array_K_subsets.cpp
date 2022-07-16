// https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



bool isKpartitionRec_util(int arr[] , vector<int>&subsetsum , vector<bool>&taken , int subset_sum , int k , int n , int cur_Indx , int las_Indx)
{
    if(subsetsum[cur_Indx]==subset_sum)
    {
        if(cur_Indx==k-2)
            return true ;

        return isKpartitionRec_util(arr,subsetsum,taken,subset_sum , k,n,cur_Indx+1,n-1);
    }
    for(int i1 = las_Indx;i1>=0 ;i1--)
    {
        if(taken[i1])
            continue ;

        int tmp = subsetsum[cur_Indx]+arr[i1];
        if(tmp<=subset_sum)
        {
            taken[i1] = true ;
            subsetsum[cur_Indx]+=arr[i1];
            bool next = isKpartitionRec_util(arr,subsetsum,taken,subset_sum,k,n,cur_Indx,i1-1);


            taken[i1] = false;
            subsetsum[cur_Indx]-=arr[i1];
            if(next)
                return true ;

        }
    }
    return false ;
}

bool isKPartitionPossible(int a[], int n, int k)
{

        //Your code here
    if(k==1)
        return true ;
    if(n<k)
        return false ;
    long long int sum1 = 0 ;
    for(int i1 = 0 ; i1<n ; i1++)
        sum1+=a[i1];
    if(sum1%k!=0)
        return false ;
    int subsetsum1 = sum1/k ;
    vector<int> subsetsum(k,0);
    vector<bool> taken(n,false);

    subsetsum[0] = a[n-1];
    taken[n-1] = true;

    return isKpartitionRec_util(a,subsetsum,taken,subsetsum1,k,n,0,n-1);
}


