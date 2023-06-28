// https://practice.geeksforgeeks.org/problems/ed0422e992899f3f46340ce97b0090683ceebd67/1









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








class Solution {
  public:
    int bitMagic(int n, vector<int> &arr) {
        // code here
        int count1 = 0;
        for (int j=0;j<n/2;j++) {
            if (arr[j]!=arr[(n-1)-j]) {
                count1++;
            }
        }
        return (count1+1)/2;
    }
};