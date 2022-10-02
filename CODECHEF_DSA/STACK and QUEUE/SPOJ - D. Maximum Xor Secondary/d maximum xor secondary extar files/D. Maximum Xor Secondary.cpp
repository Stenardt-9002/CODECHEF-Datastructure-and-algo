#include<iostream>
using namespace std;

int *max2(int arr1[],int strt,int end)
{
    int max1 = 0,max2 = 0,x;
    static int ans2[2];
    if(end-strt<2)
    {
        ans2[0] = -1;
        ans2[1] = -1;
    }
    else
    {
        if (arr1[strt+1]>arr1[strt]) 
        {
            max2 = arr1[strt+1];
            max1 = arr1[strt];
        }
        else
        {
            max2 = arr1[strt];
            max1 = arr1[strt+1];
        }
        
        
    for(int i=strt+2;i<=end;i++)
        {
            x = arr1[i];
            if (max2<x)
            {
                max1 = max2;
                max2 = x;
            }
            else if (arr1[i]>max1 && max2!=arr1[i])
            {
                max1 = arr1[i];
            }
            
        }
        ans2[0] = max2;
        ans2[1] = max1;

      }
    
    return ans2;    
 
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr1[n];
    for (int j=0;j<n;j++)
    {
        cin>>arr1[j];
    }
    int *arr2;
    int ans,ans1=0;
    // arr2 = 
    // cout<<"Read\n";
    
    int pos1 = 0,pos2 = 0;


    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i+2; j < n; j++)
        {   
            arr2 = max2(arr1,i,j);
            ans = arr2[0]^arr2[1];
            
            if (ans>ans1)
            {
                ans1 = ans;
                pos1 = i;
                pos2 = j;
            }
        }
        
    }

    // #O(n^2) not accepted


    
    

    cout<<ans1;
 
    // cout<<" "<<arr2[0]<<" "<<arr2[1];
    return 0;
}
