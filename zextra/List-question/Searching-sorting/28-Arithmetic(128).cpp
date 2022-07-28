

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




int inSequence(int A, int B, int C)
{
    // code here
    if(C==0)
    {
        if(A==B)
            return 1;
        return 0;
    }
    if((B-A)%C==0 &&((C>0 &&B>=A)||(C<0 &&B<=A) ))
        return 1 ;
    return 0 ;
}