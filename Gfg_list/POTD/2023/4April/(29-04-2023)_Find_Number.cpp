// https://practice.geeksforgeeks.org/problems/35bff0ee40090b092e97b02f649085bf1390cc67/1







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



//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        // Code here
        int arr[] = {9,1,3,5,7};
                long long digit=1;
        long res =0;
        while(N>0)
        {
            res+=arr[N%5]*digit ;    
            digit *=10;
            if(N%5==0)
                N-=5 ;
            N/=5 ;
        }
        return res;
    }
};

