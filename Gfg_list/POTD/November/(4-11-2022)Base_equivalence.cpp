// https://practice.geeksforgeeks.org/problems/base-equivalence1022/1








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


bool allowed(int base , int n, int digit)
{
    double upper = log2(n);
    double down = log2(base);
    upper = upper/down ;
    int logval = ceil(upper);
    if(logval==upper)
        return (upper+1==digit);


    return logval == digit ;

}

string baseEquiv(int n, int m)
{
    // code here
    
    for(int i1 = 2 ;i1<33;i1++)
        if(allowed(i1,n,m))
            return "Yes";

    return "No";
}















