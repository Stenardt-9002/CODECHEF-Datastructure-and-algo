


// https://practice.geeksforgeeks.org/problems/6f08220ca3b871be594f50f7f56a9ef2799cb485/1












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
    long long countSubarray(int N,vector<int> A,int M) 
    {
        // code here
        int ind = 0 ;
        long partition = 0 , res1 = 0 ,res2 = 0;
        unordered_map<int,int> hash ,hash2;
        hash[ind] = 1;
        for(int i = 0 ; i<N;i++)
        {
            int temp = -1  ;
            if(A[i]>=M)
                temp = 1 ;
            if(temp==-1)
                partition-=hash[ind-1];
            else 
                partition+=hash[ind];
                
                
            ind+=temp ;
            res1+=partition ;
            hash[ind]++;
        }
        

        ind = 0 ;
        partition = 0 ;
        hash2[ind] = 1;
        ++M;
        for(int i = 0 ; i<N;i++)
        {
            int temp = -1  ;
            if(A[i]>=M)
                temp = 1 ;
            if(temp==-1)
                partition-=hash2[ind-1];
            else 
                partition+=hash2[ind];
                
                
                
            ind+=temp ;
            res2+=partition ;
            hash2[ind]++;
        }
        
        return res1-res2 ;
    }
};

