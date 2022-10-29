// https://practice.geeksforgeeks.org/problems/filling-bucket0529/1









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



int fillingBucket(int N) 
{
    // code here
    long long int mod = 1e8 ;
    if(N==1)
        return 1 ;
    long long int ans1 = 1,ans2 = 2;
    for(int i1 = 3;i1<=N;i1++)
    {
        ans1 = (ans1+ans2)%mod ;
        swap(ans2 ,ans1);
    }
    return ans2 ;

}



// int fillingBucket(int N) {
//     // code here
//     long long int mod = 1e8 ;

//     vector<long long int>dp1(N+1,0);
//     dp1[1] = 1;
//     dp1[2] = 2;
//     for(int i1 = 3;i1<=N;i1++)
//         dp1[i1] = (dp1[i1-1]+dp1[i1-2])%mod;
        
//     return dp1[N];
// }




int main(int argc, char const *argv[])
{
    fastIO
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    int testcases=1 ;
    cin>>testcases;
    while (testcases--)
    {

    }


    return 0;
}


