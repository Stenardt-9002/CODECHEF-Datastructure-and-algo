

#include "bits/stdc++.h"

using namespace std;



// one solution O(n^2) using DP recursion function F(i,j) = 1+min(F(i+1,j),F(i,j-1));






//impemmetned solution 
// O(nlogn )




int findsecInd(int start_val , int i,int n, int k , int *arr1)
{
    int start ,end,mid,ind=-1 ; 

    start = i+1 ;
    end = n-1;

    // BS O(logn)
    while (start<end)
    {
        mid = start+(end-start)/2    ;
        if (arr1[mid]-start_val<=k)
        {
            ind = mid ; start = mid+1 ; 
        }
        else
        {
            end = mid ;
        }
    }
    return ind ;
}





int removals(int arr1[],int n , int k)
{

    int i1,j1,ans1 = n-1 ;
    sort(arr1,arr1+n) ;

    // O(n )
    for ( i1 = 0; i1 < n; i1++)
    {
        //try each element as starting get j as binary search 
        j1 = findsecInd(arr1[0],i1,n,k,arr1);

        if (j1!=-1)
        {
            //not found 
            ans1 = min(ans1,n-(j1-i1+1));

        }
        

    }
    return ans1 ;


}






int main(int argc, char const *argv[])
{

    int a[] = {1, 3, 4, 9, 10,
               11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;

    return 0;
}





