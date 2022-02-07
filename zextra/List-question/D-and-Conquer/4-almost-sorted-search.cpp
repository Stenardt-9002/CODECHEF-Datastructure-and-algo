#include<iostream>
#include<algorithm>
using namespace std;



int binarySearch1(int *arr1,int l1 , int r1 , int ele1)
{
    if(r1>=l1)
    {
        int mid1 = l1 + (r1-l1)/2 ;
        if (arr1[mid1]==ele1)
        {
                return mid1 ;
        }
        else if (mid1>l1&& arr1[mid1-1]==ele1)
        {
            return mid1-1;
        }
        
        else if (mid1<r1&& arr1[mid1+1]==ele1)
        {
            return mid1+1;
        }
        

        if (arr1[mid1]<ele1)
        {
            //go right
            return binarySearch1(arr1,mid1+2,r1,ele1);
        }
        return binarySearch1(arr1,l1,mid1-2,ele1);
        




    }
    return -1;
}








int main(int argc, char const *argv[])
{
    
    int arr1[] = {3,2,10,4,40} ;
    int n= sizeof(arr1)/sizeof(arr1[0]) ;
    int x = 4 ;
    int result1 = binarySearch1(arr1,0,n-1,x) ;

    cout<<result1<<endl;

    return 0;
}




















