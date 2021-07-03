// quicksort , mean , heap 
// #median order statistics

#include<algorithm>
#include<climits>
#include<iostream>

using namespace std ; 

int partition1(int arr1[],int l , int r , int x)
{
    int i1 ; 

    for ( i1 = l; i1 < r; i1++)
    {
        if (arr1[i1]==x)
        break ;             
        
    }
    int etmp1 = arr1[i1];
    arr1[i1] = arr1[r] ;
    arr1[r] = etmp1;

    //normal partition algorithm

    i1 = l;

    for (int j1 = i1; j1 < r; j1++)
    {
        
        if (arr1[j1]<=x)
        {
            etmp1 = arr1[i1] ;
            arr1[i1] = arr1[j1] ;
            arr1[j1] = etmp1 ; 

            i1++ ;

        }
        

    }
        etmp1 = arr1[i1] ;
        arr1[i1] = arr1[r] ;
        arr1[r] = etmp1 ; 

        
    return i1;




}

int findMedianlessthan5(int arr1[],int size2)
{
    int temp1; 
    for (int i1 = 0; i1 < size2; i1++)
    {
       for (int j1 = i1+1; j1 < size2; j1++)
       {
           if (arr1[i1]>arr1[j1])
           {
               temp1 = arr1[i1] ; 
               arr1[i1] = arr1[j1] ;
               arr1[j1] = temp1;
           }
           
       }
        
    }
    return arr1[size2/2] ;

}





int kthsmallest(int arr1[],int l,int r,int k)
{

    if (k>0  && k<=r-l+1  )
    {
        int n=r-l+1;

        int i1,median1[(n+4)/5] ; 
        for (i1 = 0; i1 < n/5; i1++)
        {
            median1[i1] = findMedianlessthan5(arr1+l+i1*5,5);
        }
        if (i1*5<n)
        {
            median1[i1] = findMedianlessthan5(arr1+l+i1*5,n%5);
            i1++;
        }
        


        int medOfmed = (i1==1)?median1[i1-1]:kthsmallest(median1,0,i1-1,i1/2) ; 


        int pos1 = partition1(arr1,l,r,medOfmed);



        if (pos1-l+1 == k)
        {
            //element found 

            return arr1[pos1] ;
        }
        if (pos1-l+1>k)
        {
            return kthsmallest(arr1,l,pos1-1,k) ; 
        }
        
        return kthsmallest(arr1,pos1+1,r,k-pos1+l-1) ; 


    }
    

    // return 0;

}

















int main(int argc, char const *argv[])
{
    
     int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is "         << kthsmallest(arr, 0, n-1, k);
    return 0;





}







