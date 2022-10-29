
// https://practice.geeksforgeeks.org/problems/sequence-fun5018/1





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





int NthTerm(int n)
{
    // Code  here
    int mod1 = 1e9+7 ;
    ll last1 = 2 ;
    bool flag = true ;
    if(n==1)
        return 2 ;
    for (int i2 = 2; i2 <=n; i2++)
    {
        last1 = last1*i2+1;
        last1%=mod1;
    }
    
    return last1;
}



int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    int testcases=1 , data;
    cin>>testcases;
    while (testcases--)
    {
        cin>>data;
        cout<<NthTerm(data)<<endl;
    }


    return 0;
}
















