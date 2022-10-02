

#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std ; 

void merge(int arr1[],int arr2[],int n , int m )
{
    int i=0,j=0,k=n-1 ; 

    while (i<=k&& j<m)
    {
        if (arr1[i]<arr2[j])
        {
            i++ ;
        }
        else
        {
            // swap1(arr1[k],arr2[j])
            int temp1 = arr1[k] ;
            arr1[k] = arr2[j] ; 
            arr2[j] = temp1 ;

            k--;j++;

        }

    }

    sort(arr1,arr1+n) ;
    sort(arr2,arr2+m) ;

    



}

int main(int argc, char const *argv[])
{
    

    int m,n ; 
    int arr1[n] , arr2[m] ; 

    cin>>n>>m ;

    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr1[i1] ;
    }
    
    for (int i1 = 0; i1 <m; i1++)
    {
        cin>>arr2[i1] ;
    }





    return 0;
}













