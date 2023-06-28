// https://practice.geeksforgeeks.org/problems/3a93b6a25a7b88e4c80a1fee00898fd8022eb108/1







#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;












class Solution {
  
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int count = 0 ;
        for(int i = 0 ; i<n ; i++)
            count+=(arr[i]==0 );
        if(count ==n)
            return 0 ;
        if(count==0)
            return 1;
            
        // if(count==0 ||count==n )
        //     return -1;
        int start = 0 ,end = n-1;
        while(arr[start]==0)
            start++ ;
        while(arr[end]==0)
            end-- ;
        count = 0 ;
        while(start<=end)
        {
            if(arr[start]==0)
            {
                while(arr[start]==0 && start<=end)
                    start++ ;
                
                count++ ;
            }
            start++ ;
        }
        return count+1 ;
    }
};