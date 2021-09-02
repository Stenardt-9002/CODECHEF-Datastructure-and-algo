#include<iostream>
#include<algorithm>

using namespace std ;





void heapify(int *arr,int n ,int i1)
{

    int largest = i1;//max heap 
    int l = 2*i1+1;
    int r = 2*i1+2;


    if (l<n&&arr[largest]<arr[l])
    {
        largest = l ; //finding largest in 3 
    }
    
    if(r<n&&arr[largest]<arr[r])
    {
        largest = r ; //finding largest in 3 
    }
    int temp1 ; 
    if (largest!=i1) //if larget is not root
    {
        temp1 = arr[largest] ;
        arr[largest] = arr[i1] ;
        arr[i1] = temp1;
        //kepp going down in tree 

        heapify(arr,n,largest); //new child to check if largest or not

    }

}


void buildHeap(int *arr , int n)
{
    //start from last level 

    int startindex = (n/2)-1; // after that nodes have no childre n


    for (int i1 = startindex; i1 >=0; i1--)
    {
        heapify(arr,n,i1) ;
        
    }
    

}

void heapsort(int *arr , int n)
{
    for (int i1 = n/2; i1 >=0; i1--)
    {
        heapify(arr,n,i1); // contructing heap
    }

    //extract data from heap
    int temp ; //get largest and send it to last
    //heap size is now also decreasing 
    for (int i1 = n-1; i1>-1; i1--)
    {
        temp = arr[i1] ;
        arr[i1] = arr[0];
        arr[0] = temp ;
        //swap elements 
        //largest is at the end 
        heapify(arr,i1,0) ; // 0 the element has to be heapified


    }
    




}



int main(int argc, char const *argv[])
{

    int n ;
    cin>>n;
    int *arr1 = new int[n] ;
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr1[i1];
    }
    

    heapsort(arr1,n);

    cout<<endl;
    for (int i1 = 0; i1 < n; i1++)
    {
        cout<<" "<<arr1[i1];
    }
    
    delete [] arr1 ;


    return 0;
}





