// https://practice.geeksforgeeks.org/problems/90a81c305b1fe939b9230a67824749ceaa493eab/1















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












class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int word_O = 0 ;
        int first = 0 ;
        int ans = 0 ;
        
        for(int j= 0 ;j<n;j++)
        {
            if(arr[j]=='O')
                word_O++ ;
            while(word_O>m)    
            {
                if(arr[first++]=='O')
                    word_O--;
            }

            ans = max(ans , j-first+1);
        }
        return ans ;
    }
};