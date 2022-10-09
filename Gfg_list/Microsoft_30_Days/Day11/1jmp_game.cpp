// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day11/problem/jump-game



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



    int canReach(int A[], int N) {
        // code here
        if(A[0]==0)
          return 0 ;
         if(N==1)
            return 1 ;

        int Reach = A[0];
        int step_taken = A[0] , jump_val = 1;
        int i1 ;
        for (i1 = 1; i1 < N; i1++)
        {
          if(Reach<i1)
            return 0 ;
          if(Reach>=N)
            return 1 ;
    
    
          Reach = max(Reach , i1+A[i1]);
        }
        return 1 ;
    }