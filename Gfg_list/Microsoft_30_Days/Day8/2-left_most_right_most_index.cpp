// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day8/problem/find-first-and-last-occurrence-of-x0849











#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



pair<long,long> indexes(vector<long long> v, long long x)
{
    // code here
    long ind = lower_bound(v.begin(),v.end(),x) -v.begin();
    if(ind==v.size()||v[ind]!=x )
        return {-1,-1} ;
    long hig = upper_bound(v.begin(),v.end(),x) -v.begin();
    return {ind , hig-1} ;
    
}
