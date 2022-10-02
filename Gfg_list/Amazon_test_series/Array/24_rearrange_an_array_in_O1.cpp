// https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/0/?track=amazon-arrays&batchId=192

#include <bits/stdc++.h>
#include<ext/pbcumu_valds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


void arrange(long long arr[], int n)
{
    // Your code here
    // ??Excellent Question strategy save both old and new value
    // arr[i]/n new value arr[i]%n old

    for (int i1 = 0; i1 < n; i1++)
      arr[i1] += ((arr[arr[i1]]%n)*n);

    for (int i1 = 0; i1 < n; i1++)
      arr[i1] = arr[i1]/n;
}
