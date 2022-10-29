// https://practice.geeksforgeeks.org/problems/the-smurfs4201/1









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






int findMin(int n, char a[])
{
    // code here
    if(n<=2)
        return n ;
    int countr = 0 , countg = 0 ,countb = 0;
    for (int i1 = 0; i1 < n; i1++)
        if(a[i1]=='R')    
            countr++ ;
        else if(a[i1]=='G')
            countg++ ;
        else 
            countb++ ;

    if(countr==n || countg==n || countb==n)
        return n ;

    else if(countr%2==0 && countg%2==0 && countb%2==0)
        return 2 ;

    else if(countr%2==1 && countg%2==1 && countb%2==1)
        return 2 ;
    return 1 ;
}



int main(int argc, char const *argv[])
{
    int n = 5;
    char a[] = {'R','G','B','R','B'};
    cout<<findMin(n,a)<<endl;;
    return 0;
}

















