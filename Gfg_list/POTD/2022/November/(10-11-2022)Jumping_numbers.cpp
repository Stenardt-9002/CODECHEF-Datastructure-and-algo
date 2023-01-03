// https://practice.geeksforgeeks.org/problems/jumping-numbers3805/1








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



// bool allow_nu(ll num)
// {
//     ll remain ;
//     while(num!=0)
//     {
//         remain = num%10 ;
//         num/=10 ;
//         if(num!=0 && abs(remain-(num%10))!=1 )
//             return false ;
//     }
//     return true ;
// }


ll bfs_ans(ll x , ll start_dig)
{    
    queue<ll> q1 ;
    q1.push(start_dig);
    ll ans1 = 0 ,last_dig ;
    ll final_ans = 0 ;
    while (!q1.empty())
    {
        ans1 = q1.front();
        q1.pop();
        if(ans1<=x)
        {
            final_ans = max(final_ans , ans1);
            last_dig = ans1%10 ;
            if(last_dig==0)
                q1.push((ans1*10)+(last_dig+1));
            else if(last_dig==9)
                q1.push((ans1*10)+(last_dig-1));
            else 
            {
                q1.push((ans1*10)+(last_dig-1));
                q1.push((ans1*10)+(last_dig+1));
            }
        }
    }
    return final_ans;

}

long long jumpingNums(long long X) 
{
    // code here
    ll ans1 = 0;
    for (ll start = 0; start <=9 && start<=X; start++)
        ans1 = max(ans1 , bfs_ans(X,start));
    

    return ans1 ;
}






