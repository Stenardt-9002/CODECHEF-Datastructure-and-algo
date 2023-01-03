
// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
//good one 
//visit trailing zero in factorial = (x/5)+(x/25)+(x/125)+(x/625).....
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;



bool verify(int fir , int n)
{
    int temp1 = fir , cunt = 0 , mul = 5 ;
    while (mul<=temp1)
    {
        cunt+=(temp1/mul);
        mul*=5;
    }
    return (cunt>=n);
}


int findNum(int n)
{
    if(n==1)
        return 5 ;


    int lo = 0 ,hi = 5*n,searc;
    while (lo<hi)
    {
        searc = (lo+hi)>>1;
        if(verify(searc,n))
            hi = searc ;
        else 
            lo = searc+1;

    }
    return lo ;
}





