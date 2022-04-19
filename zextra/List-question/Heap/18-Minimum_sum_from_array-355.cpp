
// https://practice.geeksforgeeks.org/problems/minimum-sum4058/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);

string solve(int arr[], int n) 
{
    // code here
    sort(arr,arr+n);
    string ans1="" ; 
    // long long int ans1 = 0 ;
    // long long powe_fact = 1;
    int carry1 = 0;
    int val ;
    while (n--)
    {
        if(arr[n]==0)
            break ;
        
        if(n-1>=0)
            val = arr[n]+arr[--n]+carry1;
        else 
            val = arr[n]+carry1 ;

        if (val>9)
        {
            val = val%10 ;
            carry1 = 1;
        }
        else 
            carry1 = 0; 
        
        ans1 = to_string(val)+ans1 ;
    }
    if(carry1==1)
        ans1 = "1"+ans1;
    // cout<<" "<<ans1;
    return ans1;
}

int main(int argc, char const *argv[])
{
    // int arr[] = {6,8,4,5,2,3};
    int arr[] = {5,3,0,7,4};

    solve(arr,5);
    return 0;
}

