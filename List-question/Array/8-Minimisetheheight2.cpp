
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace  std;


int getmindiff(int arr[],int n , int k )
{

        sort(arr, arr + n); // sort the array to get the
                            // corner cases ans.
        int minEle,
            maxEle; // these 2 variables will hold the
                    // between elements max and min value
        int result = arr[n - 1]
                     - arr[0]; // current result when arr[0]
                               // iss min and arr[n-1] is max
 
        for (int i = 1; i <= n - 1; i++) {
            if (arr[i] >= k && arr[n - 1] >= k) {
                maxEle = max(arr[i - 1] + k,
                             arr[n - 1] - k); //
                 if(arr[i] - k < 0)
                  continue;
                minEle = min(arr[0] + k, arr[i] - k);
 
                result = min(result, maxEle - minEle);
                // if the middle elements max and min
                // difference if less than result then update
                // result.
            }
        }
        return result; // return result.

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

























