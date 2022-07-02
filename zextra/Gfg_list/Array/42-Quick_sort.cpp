
// https://practice.geeksforgeeks.org/problems/quick-sort/1/?page=3&curated[]=2&sortBy=submissions

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high)
{
    // code here
    int i1 = low ;
    if(low<high)
    {
        int index1 = partition(arr,low ,high);
        quickSort(arr,low,index1-1);
        quickSort(arr,index1+1,high);
    }
}
    
int partition (int arr[], int low, int high)
{
   // Your code here
   int pivot = arr[low] ;
   int i = low,j=high;
   while(i<j)
   {
        while(pivot>=arr[i])
            i++ ;
        while(pivot<arr[j])
            j-- ;
        if(i<j)
            swap(arr[i],arr[j]);
   }
    swap(arr[low],arr[j]);
    return j ;

}






