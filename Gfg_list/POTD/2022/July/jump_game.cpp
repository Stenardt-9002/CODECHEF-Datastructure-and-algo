// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
//good one
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


int canReach(int A[], int N)
{
    // code here

    if(A[0]==0)
      return 0 ;

    int Reach = A[0];
    int step_taken = A[0] , jump_val = 1;
    int i1 ;
    for (i1 = 1; i1 < N; i1++)
    {
      if(i1==N-1)
        return 1 ;

      Reach = max(Reach , i1+A[i1]);
      step_taken--;
      if(step_taken==0)
      {
        jump_val++;
        if(i1>=Reach)
          return 0 ;

        step_taken = Reach-1 ;
      }
    }
    return 1 ;
}



int canReach(int A[], int N) {
    // code here
    if(A[0]==0)
      return 0 ;
     if(N==1)
        return 1 ;

    int Reach = A[0];
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
