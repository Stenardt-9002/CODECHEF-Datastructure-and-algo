// https://practice.geeksforgeeks.org/problems/third-largest-element/0/?track=amazon-arrays&batchId=192


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



int thirdLargest(int a[], int n)
{
  if(n<3)
     return -1 ;

 // sort(a,a+n);
 // return a[n-3];
  int max1 = max({a[0],a[1],a[2]});
  int max2  ;
  int max3 ;
  for(int i1=0;i1<3;i1++)
     if(max1==a[i1])
         max2 = max(a[(i1+1)%3] , a[(i1+2)%3]) , max3 = min(a[(i1+1)%3] , a[(i1+2)%3]);


  for(int i1=3;i1<n;i1++)
  {
     if(a[i1]>max1)
     {
         max3 = max2 ;
         max2 = max1 ;
         max1 = a[i1];
     }
     else if(a[i1]>max2)
     {
         max3 = max2 ;
         max2 = a[i1];
     }
     else if(a[i1]>max3)
         max3 = a[i1];

  }
  return max3;
}

int main(int argc, char const *argv[])
{
    int n  ;
    cin>>n ;
    int *arr1 = new int[n];

    for (int i1 = 0; i1 < n; i1++)
        cin>>arr1[i1];

      cout<<thirdLargest(arr1,n);
    delete []arr1;
    return 0;
}
