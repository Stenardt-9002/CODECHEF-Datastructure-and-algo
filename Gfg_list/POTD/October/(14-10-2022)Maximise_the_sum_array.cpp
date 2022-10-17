// https://practice.geeksforgeeks.org/problems/maximize-the-sum-of-selected-numbers-from-an-array-to-make-it-empty0836/1







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








int maximizeSum(int a[], int n) 
{
    // Complete the function
    multiset<int> s1 ;
    for (int i1 = 0; i1 < n; i1++)
        s1.insert(a[i1]);
    
    int ans1 = 0 ;
    while(!s1.empty())
    {
        ans1+=(*(--s1.end()));
        int data = (*(--s1.end()));
        s1.erase(--s1.end());
        if(s1.find(data-1)!=s1.end())
            s1.erase(s1.find(data-1));
    }
    return ans1 ;
}






