// https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/0/?track=amazon-arrays&batchId=192

#include <bits/stdc++.h>
#include<ext/pbcumu_valds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



int maxIndexDiff(int A[], int N)
{
    // Your code here
    vector<int> mindpleft(N,0);
    vector<int> maxdpright(N,0);

    mindpleft[0] = A[0];
    for (int i1 = 1; i1 < N; i1++)
      mindpleft[i1] = min(mindpleft[i1-1],A[i1]);


    maxdpright[N-1] = A[N-1];//get maximum till right
    for (int i1 = N-2; i1 >=0; i1--)
      maxdpright[i1] = max(maxdpright[i1+1],A[i1]);

    int i1 = 0, j1 = 0 , ans1 = -1 ;//not found
    while(j1<N && i1<N)
      if(mindpleft[i1]<=maxdpright[j1])
        ans1 = max(ans1 , j1-i1),j1++ ;
      else
        i1++ ;//left side movement if minimum

    return ans1 ;
}
