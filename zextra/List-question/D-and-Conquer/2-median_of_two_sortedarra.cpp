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


int getFunc(int *arr1,int *arr2,int n)
{

    if (n<0)
    {
        return -1 ;
    }


    //     cout<<endl<<"Arr1" ;

    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cout<<" "<<arr1[i1] ;
    // }

    //     cout<<endl<<"Arr2" ;
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cout<<" "<<arr2[i1] ;
    // }



    if (n==1)
    {
        return (arr1[0]+arr2[0])/2;
    }
    if (n==2)
    {
        //array are sorted
        return ( max(arr1[0],arr2[0] ) + min(arr1[1],arr2[1]) )/2;
    }
    int m1 = median1(arr1,n); int m2 = median1(arr2,n) ;
    if (m1==m2)
    {
        return m1 ;
    }
    else if (m1<m2)
    {
        if (n%2==0)
        {
            return getFunc(arr1+n/2-1,arr2,n-n/2+1);
        }
        else
        {
            return getFunc(arr1+n/2,arr2,n-n/2);
        }
    }
    else
    {
        if (n%2==0)
        {
            return getFunc(arr2+n/2-1,arr1,n-n/2+1);
        }
        else
        {
            return getFunc(arr2+n/2,arr1,n-n/2);
        }
    }
    
}







int main(int argc, char const *argv[])
{
    // long long int x, y,res = 1;

    int n;cin>>n;
    int *arr1,*arr2 ;
    arr1 = new int[n] ;arr2 = new int[n] ;


    for (int i1 = 0; i1 < n; i1++) { cin>>arr1[i1];  }
    for (int i1 = 0; i1 < n; i1++) { cin>>arr2[i1];  }

    cout << getFunc(arr1,arr2,n);







    delete []arr1; delete []arr2;


    return 0;
}
















