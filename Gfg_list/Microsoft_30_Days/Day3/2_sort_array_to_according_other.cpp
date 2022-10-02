// https://practice.geeksforgeeks.org/problems/relative-sorting4323/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
{
    //Your code here
    map<int,int> hash_1 ;
    for(int i1 = 0 ; i1< N ; i1++)
        hash_1[A1[i1]]++ ;

    vector<int> ans1 ; 
    for (int i1 = 0; i1 < M; i1++)
        if(hash_1.find(A2[i1])!=hash_1.end())
        {
            while (hash_1[A2[i1]]--)
                ans1.push_back(A2[i1]);
            hash_1.erase(A2[i1]) ;
        }
    for(auto &x : hash_1)
        while (x.second--)
            ans1.push_back(x.first);

    return ans1 ;

} 




