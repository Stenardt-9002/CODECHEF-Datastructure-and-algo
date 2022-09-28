
// https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1



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

const long long int mod2 =  1e18 ;




vector<int> max_of_subarrays(vector<int> arr, int n, int k) 
{
    // your code here

    vector<int> ans1 ;
    deque<int> Q(k);
    for (int i1 = 0; i1 < k; i1++)
    {
        while(!(Q.empty()) && arr[i1]>=arr[Q.back()] )
            Q.pop_back();
        Q.push_back(i1);
    }

    for (int i1 = k; i1 < n; i1++)
    {
        ans1.push_back(arr[Q.front()]);
        while (!Q.empty() && arr[i1]>=arr[Q.back()])
            Q.pop_back();

        while (!Q.empty() && i1-k>=Q.front())
            Q.pop_front();

        Q.push_back(i1);
    }
    
    ans1.push_back(arr[Q.front()]);
    return ans1 ;

}



