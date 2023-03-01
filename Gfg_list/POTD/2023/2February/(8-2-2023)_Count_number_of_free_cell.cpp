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
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr)
  {
      int countrow = 0 , countcol = 0 ;
      vector<bool> row_bool(n,false) , col_bool(n,false);
      vector<long long int> ans ;
      long long int init = n*n ;

      for(auto vec : arr)
      {
        int first = vec[0]-1;
        int secon = vec[1]-1;
        if(!row_bool[first] && !col_bool[secon])
        {
            row_bool[first] = col_bool[secon] = true ;
            long long int curre_count = n-countrow+n-countcol-1 ;
            countrow++ ;
            countcol++ ;
            init-=curre_count ;
        }
        else if(row_bool[first] && !col_bool[secon])
        {
            col_bool[secon] = true ;
            long long int curre_count = n-countrow ;
            countcol++ ; 
            init-=curre_count ;
        }
        else if(!row_bool[first] && col_bool[secon])
        {
            row_bool[first] = true ;
            long long int curre_count = n-countcol ;
            countrow++ ; 
            init-=curre_count ;
        }
        ans.push_back(init);
      }

      return ans ;
  }
};







