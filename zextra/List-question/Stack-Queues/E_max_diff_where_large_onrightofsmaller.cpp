// https://www.geeksforgeeks.org/maximum-difference-between-two-elements/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;



int maxDiff(vector<int>arr1)
{
    int n = arr1.size();
    int min1 = arr1[0];
    int max1 = INT_MIN ;
    for (int i1 = 1; i1 < n; i1++)
    {
        if(min1>arr1[i1])
        {
            min1 = arr1[i1] ;
        }
        else
        {
            max1 = max(max1 , arr1[i1]-min1);
        }
    }
    return max1 ;
    
}
//similar approach from right side keep track of max 




