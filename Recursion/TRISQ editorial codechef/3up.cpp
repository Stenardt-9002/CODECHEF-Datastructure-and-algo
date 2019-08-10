#include<iostream>
using namespace std;

int func(int n,int arr[])
{
    if (n <4)
    {
        return 0 ;
    }
    else
    {
        return ((n/2)-1)+func(n-2,arr);
    }
    
}

int main(int argc, char const *argv[])
{
    int t,b;
    long ans;
    cin>>t;
    int arr1[10000];
    for (size_t i = 0; i < t; i++)
    {
        cin>>b;
        if (arr1[b]==0 && b>3)
        {
            ans = func(b,arr1);
        }
        else
        {
            ans = arr1[b];
        }
        
        cout<<ans;
    }
    
    return 0;
}
