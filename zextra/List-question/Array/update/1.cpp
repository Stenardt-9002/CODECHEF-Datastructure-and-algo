
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace  std;


int getmindiff(int arr1[],int n , int k )
{

    sort(arr1,arr1+n);
    int asnwer = arr1[n-1] - arr1[0]; //both increment or both decrement no sense for incrementing large one and dcrementing small one because minimise sum
    int maxEle, minEle ;

//adjacent numbers the next is largers than previous therefore diffeit by k and previous number icrementing by k will give the smallest difference 
    for (int i2 = 0; i2 < n-1; i2++)
    {
        if (arr1[i2+1]>=k && arr1[n-1]>=k )
        {

            maxEle = max(arr1[n-1]-k,arr1[i2]+k );
            if (arr1[i2+1]>=k   )
            {
                minEle = min(arr1[0]+k,arr1[i2+1]-k );
                asnwer = min(asnwer, maxEle-minEle) ;

            }
            
        }
    }
    
    return asnwer;


}








int main(int argc, char const *argv[])
{
    int n ,k ;
    cin>>k>>n ; 
    int arr1[n];
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr1[i1];
    }
    int ans = getmindiff(arr1,n,k);

    cout<<endl<<ans;
    


    return 0;
}

















    // int getMinDiff(int arr1[], int n, int k) 
    // {
    
    // sort(arr1,arr1+n);
    // int asnwer = arr1[n-1] - arr1[0]; //both increment or both decrement no sense for incrementing large one and dcrementing small one because minimise sum
    // int maxEle, minEle ;


    // for (int i2 = 0; i2 < n-1; i2++)
    // {
    //     if (arr1[i2+1]>=k && arr1[n-1]>=k )
    //     {

    //         maxEle = max(arr1[n-1]-k,arr1[i2]+k );
    //         if (arr1[i2+1]>=k   )
    //         {
    //             minEle = min(arr1[0]+k,arr1[i2+1]-k );
    //             asnwer = min(asnwer, maxEle-minEle) ;

    //         }
            
    //     }
    // }
    
    // return asnwer;
   
        
        
        
    // }







