
// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day14/problem/next-larger-element-1587115620





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
long long getMaxArea(long long arr[], int n)
{
    // Your code here
    vector<ll> smalleronleft(n , -1);
    vector<ll> smalleronright(n , -1);

}
vector<ll> nextlargerElement(vector<ll> arr , int n)
{
    vector<ll> ans1(n,-1) ; 
    stack<ll> s1 ;
    s1.push(0);
    for (ll i = 1; i < n; i++)
    {
        while (!s1.empty() && arr[s1.top()]<arr[i])
        {
            ans1[s1.top()] = arr[i];
            s1.pop();
        }
        s1.push(i);
    }
    return ans1 ;
}














