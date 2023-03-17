


// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/













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








long long int no_of_subarrays(int n, vector<int> &arr) 
{
    // Write your code here.
    
    long long int ans = 0 ;
    int first = 0 ,second = 0;
    while(second<n)
    {
        if(arr[second]==1)
        {
            long long int leng = second-first;
            leng = ((leng)*(leng+1)/2);
            ans+=leng ;
            first = second+1;
            second = first ;
        }
        else
            second++ ;
    }
    long long int leng = second-first;
    for(int le = 1 ; le<leng+1;le++)
    ans+=le;
    
    return ans ;
    
}