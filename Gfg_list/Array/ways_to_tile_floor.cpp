
// https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1/#

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




long long int a=0,b=1,c ;
int MOD1 = 1000000007 ;
for(long long int i1=0;i1<N ; i1++)
{
    c = (a+b) ;
    a=b%MOD1;
    b=c%MOD1;
}
return b%MOD1 ;
