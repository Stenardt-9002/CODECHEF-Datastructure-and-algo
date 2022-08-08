#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout


    int josephus(int n, int k)
    {
       
        k--;
        vector<int> arr(n,1);
        int count1 = 0, breaks1 = 0,
        num = 1;
        while (count1 < (n - 1)) 
        {
            while (num <= k) 
            {
                breaks1++;
 
                breaks1 = breaks1 % n;
                if (arr[breaks1] == 1) 
                num++;
            }
 
            num = 1;
            arr[breaks1] = 0;
            count1++;
            breaks1++;
            breaks1 = breaks1 % n;
            while (arr[breaks1] == 0) 
            {
                breaks1++;
                breaks1 = breaks1 % n;
            }
        }
    return breaks1 + 1;
    }