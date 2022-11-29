// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day13/problem/find-duplicate-rows-in-a-binary-matrix








#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

const int mod1 = (1e9+7);
const long long int mod2 =  1e18 ;

#define mii map<int,int> 
#define msi map<string,int> 
#define musi unordered_map<string,int> 

typedef  long long int lld;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) 
{ 
    // Your code here
    vector<int> ans1 = {};
    set<string> hash_1 ;
    for (int i1 = 0; i1 < M; i1++)
    {
        string current = "" ;
        for (int j1 = 0; j1 < N; j1++)
            current+=to_string(matrix[i1][j1]);

        if(hash_1.find(current)!=hash_1.end())
            ans1.push_back(i1);
        else 
            hash_1.insert(current);
    }
    return ans1 ;
  
} 


















