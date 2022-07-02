// https://practice.geeksforgeeks.org/problems/matrix-exponentiation2711/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

// #define MOD1 1000000007



void multply_mat(long long int F[2][2], long long int X[2][2])
{
    int MOD1 = 1000000007;
    long long int x = F[0][0]*X[0][0]+F[0][1]*X[1][0];
    long long int y = F[0][0]*X[0][1]+F[0][1]*X[1][1];
    long long int z = F[1][0]*X[0][0]+F[1][1]*X[1][0];
    long long int a = F[1][0]*X[0][1]+F[1][1]*X[1][1];

    F[0][0] = x%MOD1 ;
    F[0][1] = y%MOD1 ;
    F[1][0] = z%MOD1 ;
    F[1][1] = a%MOD1 ;
}

void power(long long int F[2][2],long long int n)
{
    int MOD1 = 1000000007;
    if(n==0||n==1)
        return ;
    long long int X[2][2] = {{1,1},{1,0}};
    power(F,n/2);
    multply_mat(F,F);
    if(n%2!=0)
        multply_mat(F,X);

}

int FindNthTerm(long long int n) 
{
    // Code here
    int MOD1 = 1000000007;
    if(n==0)
        return 1 ;
    // n++;
    long long int F[2][2] = {{1,1},{1,0}};
    power(F,n);
    return F[0][0]%MOD1;
}











