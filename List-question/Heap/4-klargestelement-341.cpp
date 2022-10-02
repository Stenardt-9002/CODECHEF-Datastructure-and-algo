#include<iostream>
#include<algorithm>
#include<vector>



// n+klogn 


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


	vector<int> kLargest(int arr[], int n, int k) 
	{
	    vector<int> asnwer ;
	    int temp1 ;
	    buildHeap(arr,n);
	   for(int i=0;i<k;i++)
	   {
	       asnwer.push_back(arr[0]) ;
	       temp1 = arr[0] ; arr[0] = arr[n-i-1] ; arr[n-i-1] = temp1;
	       heapify(arr,n-i-1,0);
	       
	   }
	   //reverse(asnwer.begin(),asnwer.end()) ;
	   return asnwer;
	    
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
    
    return 0;
}




//try n +klogk // using i th order statistics and k size heap

