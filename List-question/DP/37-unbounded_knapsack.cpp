// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

#include "bits/stdc++.h"

using namespace std;





int knapSack(int N, int W, int val[], int wt[])
{
// TC O(n^2)
int n = N;
vector<int> dp1(W+1,0) ;// all weights

    for (int i1 = 0; i1 < W+1; i1++)//all weights
    {
        for (int j1 = 0; j1 < n; j1++)//all items
        {
            if (i1>=wt[j1])
            {
                dp1[i1] = max(dp1[i1],dp1[i1-wt[j1]]+val[j1]  ) ;//dp1 contains max cost for ith weight
            }
        }
    }
    return dp1[W];
}




int main(int argc, char const *argv[])
{




    return 0;
}



