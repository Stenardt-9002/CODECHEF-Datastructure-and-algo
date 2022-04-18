#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);




vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) 
{
    // your code here
    // int n = a.size();
    // int m = b.size();
    vector<int> temp1(n+m,0) ;
    std::merge(a.begin(),a.end(),b.begin(),b.end(),temp1.begin());
    make_heap(temp1.begin(),temp1.end());
    return temp1 ;
}


