// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


int kth_func(int start1 , int end1 , int start2 , int end2 , int k,vector<int>ar1,vector<int>ar2)
{
    if(start1==end1-1)
        return ar2[k];
    if(start2==end2-1)
        return ar1[k];

    int mid1 = (start1+end1)>>1;
    int mid2 = (start2+end2)>>1;

    if (mid1+mid2<k)
    {
        if(ar1[mid1]>ar2[mid2])
            {
                if(DEBUG_var==1)
                    cout<<"DEBUG1 "<<ar1[start1]<<" "<<ar2[start2]<<" "<<ar1[end1-1]<<" "<<ar2[end2-1]<<" "<<k<<" "<<endl ;
                    // cout<<"DEBUG1 "<<start1<<" "<<start2<<" "<<mid1<<" "<<mid2<<" "<<end1<<" "<<end2<<" "<<k<<" "<<endl ;


                return kth_func(start1,end1,start2+mid2+1,end2,k-mid2-1,ar1,ar2);
            }

        else 
            {
                if(DEBUG_var==1)
                    cout<<"DEBUG2 "<<ar1[start1]<<" "<<ar2[start2]<<" "<<ar1[end1-1]<<" "<<ar2[end2-1]<<" "<<k<<" "<<endl ;
                    // cout<<"DEBUG2 "<<start1<<" "<<start2<<" "<<mid1<<" "<<mid2<<" "<<end1<<" "<<end2<<" "<<k<<" "<<endl ;
                return kth_func(start1+mid1+1,end1,start2,end2,k-mid1-1,ar1,ar2);
            }

    }

    else
    {
        if(ar1[mid1]>ar2[mid2])
            {
                if(DEBUG_var==1)
                    cout<<"DEBUG3 "<<ar1[start1]<<" "<<ar2[start2]<<" "<<ar1[end1-1]<<" "<<ar2[end2-1]<<" "<<k<<" "<<endl ;
                    // cout<<"DEBUG3 "<<start1<<" "<<start2<<" "<<mid1<<" "<<mid2<<" "<<end1<<" "<<end2<<" "<<k<<" "<<endl ;
                return kth_func(start1,start1+mid1,start2,end2,k,ar1,ar2);
            }

        else 
            {
                if(DEBUG_var==1)
                    cout<<"DEBUG4 "<<ar1[start1]<<" "<<ar2[start2]<<" "<<ar1[end1-1]<<" "<<ar2[end2-1]<<" "<<k<<" "<<endl ;
                    // cout<<"DEBUG4 "<<start1<<" "<<start2<<" "<<mid1<<" "<<mid2<<" "<<end1<<" "<<end2<<" "<<k<<" "<<endl ;
                return kth_func(start1,end1,start2,start2+mid2,k,ar1,ar2);
            }
        
    }
    
    

        
}



int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    vector<int> ar1(n,0),ar2(n,0);
    
    for (int i1 = 0; i1 < n; i1++)
        ar1[i1] = arr1[i1]    ;

    for (int i1 = 0; i1 < m; i1++)
        ar2[i1] = arr2[i1]    ;

    int start1 =0,end1 = n;
    int start2 =0,end2 = m;

    return kth_func( start1 ,end1,start2,end2,k-1,ar1,ar2);


}


int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
    if (arr1 == end1)
        return arr2[k];
    if (arr2 == end2)
        return arr1[k];
    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    if (mid1 + mid2 < k)
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2 + mid2 + 1, end1, end2,
                k - mid2 - 1);
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2,
                k - mid1 - 1);
    }
    else
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2, arr1 + mid1, end2, k);
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k);
    }
}


int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);


    int n , m ;
    cin>>n>>m ;
    int *arr1 = new int[n];
    int *arr2 = new int[m];
    int k ; cin>>k ;
    for (int i1 = 0; i1 < n; i1++)
        cin>>arr1[i1]    ;

    for (int i1 = 0; i1 < m; i1++)
        cin>>arr2[i1]    ;
    
    // for (int i1 = 1; i1 < n+m; i1++)
    // cout<<endl<<kthElement( arr1, arr2 , n, m, i1);
        
    

    cout<<endl<<kthElement( arr1, arr2 , n, m, k);

    return 0;
}


