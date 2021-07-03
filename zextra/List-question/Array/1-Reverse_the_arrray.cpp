


#include<iostream>

using namespace std ; 



void reserveArray(int *arr1 , int start ,int end)
{

    while (start<end)
    {
        int temp1 = arr1[start];
        arr1[start] = arr1[end] ;
        arr1[end] = temp1 ;
        start++ ; end --;

    }
    


}










int main(int argc, char const *argv[])
{
    // int ar1[] = {1,2,3,4,5,6} ;
    int ar1[] = {1,2,3,4,5,6,7} ;

    int nsize = sizeof(ar1)/sizeof(ar1[0]);

    // cout<<nsize;

    // delete [] ar1 ; 
    reserveArray(ar1,0,nsize-1) ; 
    for (int i1 = 0; i1 < nsize; i1++)
    {
        cout<<" "<<ar1[i1] ;
    }
    
    return 0;
}













