// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day7/problem/coin-piles5152



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);





int minSteps(int A[], int N, int K) 
{
    // code here
    sort(A,A+N);
    // int minval = *min_element(A,A+N);
    vector<int>cumulative(N,0);
    cumulative[0] = A[0];
    for (int i1 = 1; i1 < N; i1++)
        cumulative[i1] = cumulative[i1-1]+A[i1];
    
    int ans1 = INT_MAX ;
    for (int i1 = 1; i1 < N; i1++)
    {
        int pos = upper_bound(A,A+N , A[i1]+K)-A ;
        ans1 = min(ans1 , cumulative[i1-1]+(cumulative[N-1]-cumulative[pos-1])-((N-pos)*(A[i1]+K ) )  );
    }
    


    return ans1 ;

}


