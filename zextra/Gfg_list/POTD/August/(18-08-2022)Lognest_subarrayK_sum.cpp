// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1






#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    
    // Complete the function
    unordered_map<int,int> hash_map ;
    int sum1 = 0 ;
    int ans1_len = 0 ;
    for (int i1 = 0; i1 < N; i1++)
    {
        sum1+=A[i1];
        if(sum1 == K)
            ans1_len = i1+1 ;
        if(hash_map.find(sum1)==hash_map.end())
            hash_map[sum1] = i1;
        if(hash_map.find(sum1-K)!=hash_map.end())
            ans1_len = max(ans1_len, i1-hash_map[sum1-K]);

    }    

    return ans1_len ;


} 

// int lenOfLongSubarr(int A[],  int N, int K) 
// { 
    
//     // Complete the function
//     int i1 =0 , j1=0 ;
//     int sum1 = 0 ;
//     int ans1_len = 0 ;
//     while(i1<N)
//     {
//         sum1+=A[i1];
//         if(sum1 == K)
//             ans1_len = max(i1-j1+1,ans1_len) ,i1++ ;
//         else if(sum1>K)
//         {
//             while(sum1>K)
//             {
//                 sum1-=A[j1];
//                 j1++ ;
//             }
//             if(sum1 == K)
//                 ans1_len = max(i1+1-j1,ans1_len) ;

//             i1++ ;                
//         }
//         else
//             i1++ ;

//     }    

//     return ans1_len ;


// } 


