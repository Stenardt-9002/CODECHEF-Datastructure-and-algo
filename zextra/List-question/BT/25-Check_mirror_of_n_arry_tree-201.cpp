// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



int checkMirrorTree(int n, int e, int A[], int B[]) 
{
    // code here
        unordered_map<int,stack<int>> map_hash1 ;
        for (int i1  = 0; i1 < 2*e; i1+=2)
            map_hash1[A[i1]].push(A[i1+1]);
    
        for (int i1  = 0; i1 < 2*e; i1+=2)
        {   if(map_hash1[B[i1]].top()!=B[i1+1] )    
                return 0 ;
            map_hash1[B[i1]].pop() ;
        }
            
        return 1 ;
}

int main(int argc, char const *argv[])
{
    int arr1[] = {1,2,1,3};
    int arr2[] = {1,3,1,2};
    checkMirrorTree(3,2,arr1,arr2);
    return 0;
}
