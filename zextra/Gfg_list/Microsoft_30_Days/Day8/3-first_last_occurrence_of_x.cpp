    
    
    // https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day8/problem/first-and-last-occurrences-of-x2041


    




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

const long long int mod2 =  1e18 ;
    vector<int> firstAndLast(vector<int> &arr, int n, int x) 
    {
        int lowerans1 = -1;
        int low = 0 , high = n-1 ;
        while(low<=high)
        {
            int mid = (low+high)>>1 ;
            
            if(arr[mid]==x)
            {
                lowerans1 = mid ;
                high = mid-1;
            }
            else if(arr[mid]>x)
                high = mid-1 ;
            else 
                low = mid+1 ;
        }
        if(lowerans1==-1)
            return {-1};
        int upperans1 = -1;
        low = 0 , high = n-1 ;
        while(low<=high)
        {
            int mid = (low+high)>>1 ;
            
            if(arr[mid]==x)
            {
                upperans1 = mid ;
                low = mid+1;
            }
            else if(arr[mid]>x)
                high = mid-1 ;
            else 
                low = mid+1 ;
        }
        
        return {lowerans1 , upperans1};
    }