// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1/?page=2&curated[]=2&sortBy=submissions



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


long long maxProduct(vector<int> arr, int n) 
{
    // code here 
    long long int prod_max = arr[0];
    long long int prod_min = arr[0];
    long long int ans1 = arr[0] ;
    
    long long int one_var = 1;
    long long int temp1 = 1;
    bool flag = false ;
    for(int i1 = 1 ; i1<n ;i1++)
    {
        long long int arr_Val = arr[i1];
        temp1 = max({arr_Val , arr_Val*prod_max , arr_Val*prod_min  });
        prod_min = min({arr_Val , arr_Val*prod_max , arr_Val*prod_min });
        prod_max = temp1 ; 
        ans1 = max(prod_max , ans1);
    }
    return ans1 ;
}

