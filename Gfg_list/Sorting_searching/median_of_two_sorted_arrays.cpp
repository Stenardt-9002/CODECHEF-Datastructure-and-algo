// https://leetcode.com/problems/implement-trie-prefix-tree/







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


double MedianOfArrays(vector<int>& array1, vector<int>& array2)
{
    // Your code goes here
    int n1 = array1.size();
    int n2 = array2.size();
    if(n1>n2)
        return MedianOfArrays(array2 , array1);
    int low = 0 ,high = n1 ;
    while (low<=high)
    {
        int cut1 = (low+high)>>1;
        int cut2 = ((n1+n2+1)/2) - cut1 ;

        int left1 = (cut1==0)?INT_MIN : array1[cut1-1];
        int left2 = (cut2==0)?INT_MIN : array2[cut2-1];

        int right1 = (cut1==n1)?INT_MAX : array1[cut1];
        int right2 = (cut2==n2)?INT_MAX : array2[cut2];

        if(left1<=right2 && left2<=right1)
        {
            if((n1+n2)%2==0)
                return ((double)(max(left1,left2))+(double)(max(right1,right2)))/2.0;
            else 
                return max(left1,left2);
        }
        else if(left1>right2)
        high = cut1-1;
        else 
            low = cut1+1 ;
    }
    return 0 ;    

}


















double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n = array1.size();
        int m = array2.size();
        if (n > m)
            return MedianOfArrays(array2, array1); 
     
        int start = 0;
        int end = n;
        int realmidinmergedarray = (n + m + 1) / 2;
     
        while (start <= end) {
            int mid = (start + end) / 2;
            int leftAsize = mid;
            int leftBsize = realmidinmergedarray - mid;
            int leftA
                = (leftAsize > 0)
                      ? array1[leftAsize - 1]
                      : INT_MIN; 
            int leftB
                = (leftBsize > 0) ? array2[leftBsize - 1] : INT_MIN;
            int rightA
                = (leftAsize < n) ? array1[leftAsize] : INT_MAX;
            int rightB
                = (leftBsize < m) ? array2[leftBsize] : INT_MAX;
     

            if (leftA <= rightB and leftB <= rightA) {
                if ((m + n) % 2 == 0)
                    return (max(leftA, leftB)
                            + min(rightA, rightB))
                           / 2.0;
                return max(leftA, leftB);
            }
            else if (leftA > rightB) {
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return 0.0;
    
    }

