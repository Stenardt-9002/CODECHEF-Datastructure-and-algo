#include<iostream>
#include<algorithm>
using namespace std;



int median1(int *arr,int n)
{
    int temp1;
    if (n%2==0)
    {
        temp1 = arr[n/2]+arr[(n/2)-1];
        temp1 = temp1/2;
    }
    else
    {
        temp1 = arr[n/2];
    }
    return temp1 ;
    
}
