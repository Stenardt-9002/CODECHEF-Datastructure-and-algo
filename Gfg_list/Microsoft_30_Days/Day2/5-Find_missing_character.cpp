// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day2/problem/in-first-but-second5423



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);





vector<long long> findMissing(long long A[], long long B[],  
                int N, int M) 
{ 
    // Your code goes here
    unordered_set<long long> storeb ;
    vector<long long> ans1 ;
    for(int x=0 ;x<M;x++)
        storeb.insert(B[x]);

    for(int x=0 ;x<N;x++)
        if(storeb.find(A[x])==storeb.end() )
            ans1.push_back(A[x]);

    return ans1 ;
} 


