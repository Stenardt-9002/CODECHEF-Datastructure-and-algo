// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day7/problem/killing-spree3020









#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


long long int killinSpree(long long int n)
{
    // Code Here
    // 1+4+9+ ,,T = a(a+1)(2a+1)/6     a = sqrt(T)

    long long int low1 = 1 ,high1 = sqrt(n) ;
    long long int ans1 = low1;
    while(low1<=high1)
    {
        long long int mid1 = (low1+high1)>>1; 
        long long int compa = (mid1)*(mid1 +1)*(2*mid1 + 1)/6;
        if(compa>n)
            high1 = mid1-1 ;
        else 
        {
            ans1 = mid1;
            low1 = mid1+1 ;
        }
    }
    return ans1 ;
}



int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    int testcase ;
    long long int n;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n ;
        cout<<"FUCKEM "<<killinSpree(n)<<endl ;
    }
    return 0 ;
}



