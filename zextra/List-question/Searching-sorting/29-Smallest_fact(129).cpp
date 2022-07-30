// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int trailingzero(int val)
{
    int atleast_zero = 0 ;
    int powe = 5 ;
    while((val/powe)!=0)
    {
        atleast_zero+=(val/powe);
        powe*=5 ;
    }
    return atleast_zero ; 
}


int findNum(int n)
{
//complete the function here
    if(n==0)
        return 0;
    if(n==1)
        return 5 ;
    int loe = 5 ;
    int high = 5*n ;
    int ans1 = high;
    while(loe<=high)
    {
        int mid = (loe+high)>>1;
        if(trailingzero(mid)>=n)
        {
            ans1 = mid ;
            high = mid-1 ;
        }
        else 
            loe = mid+1 ;
    }
    return ans1 ;
}

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);


    int n ;//, m ;
    cin>>n;
    cout<<endl<<findNum(n);

    return 0;
}


