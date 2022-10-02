
#include<iostream>
#include<algorithm>


using namespace std;



int first(int arr[],int x , int n)
{
    int low = 0 ,high = n-1 , res = -1 ;
    int mid ;
    while (low<=high)
    {
        mid = low+(high-low)/2 ;
        if (arr[mid]>x )
        {
            //go left 
            high = mid-1;
        }
        else if (arr[mid]<x)
        {
            low = mid+1 ;
        }
        else
        {
            res = mid ; //hit
            high = mid-1; //first value
        }
        
        


    }
    return res ;



}
int last(int arr[],int x , int n)
{

    int low = 0 ,high = n-1 , res = -1 ;
    int mid ;
    while (low<=high)
    {
        mid = low+(high-low)/2 ;
        if (arr[mid]>x )
        {
            //go left 
            high = mid-1;
        }
        else if (arr[mid]<x)
        {
            low = mid+1 ;
        }
        else
        {
            res = mid ; //hit
            low = mid+1; //first value
        }
        
        


    }
    return res ;

}





int main(int argc, char const *argv[])
{
    int arr1[] = {1,3,5,5,5,5,6,7,123,125};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    ;
    cout<<first(arr1,7,n)<<" "<<last(arr1,7,n);
    return 0;
}



























