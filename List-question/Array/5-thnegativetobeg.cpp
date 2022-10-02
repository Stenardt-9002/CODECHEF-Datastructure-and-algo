
#include <bits/stdc++.h>
using namespace std;
int countIter= 0 ;
void rearrange(int arr1[],int n)
{
    int j=0;
    for (int i1 = 0; i1 < n; i1++)
    {
        if (arr1[i1]<0)
        {
            //negative
            if (i1!=j)
            {
                swap(arr1[i1],arr1[j]);
            }
            j++;
        }
        
    }
    
}


//keep postive counters and swap from any negative further









int main(int argc, char const *argv[])
{



    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    for (int i1 = 0; i1 < n; i1++)
    {
        printf("%d ",arr[i1]);
    }
    
    
    return 0;
}














