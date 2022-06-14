// https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




int trailingZeroes(int N)
{
    // Write Your Code here
    int cunt = 0;
    int divide_by = 5;

    while (divide_by<=N)
    {
        cunt+=(N/divide_by);
        divide_by*=5 ;
    }
    return cunt ;
}

int main(int argc, char const *argv[])
{

    // cout<<endl<<trailingZeroes(5);
    // int N=5 ,c=5 ;
    // cout<<N/c;
    cout<<(45>>1);
    return 0    ;
}


