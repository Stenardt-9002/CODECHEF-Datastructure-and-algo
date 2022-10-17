
// https://practice.geeksforgeeks.org/problems/max-min/1



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







    int findSum(int A[], int N)
    {
    	//code here.
    	int min1 = INT_MAX ,max1 = INT_MIN ,i = 0;
    	for(i=0;i<N;i++)
    	    min1 = min(min1 , A[i]) ,max1 = max(max1 , A[i]);
    	
    	return max1+min1 ;
    }