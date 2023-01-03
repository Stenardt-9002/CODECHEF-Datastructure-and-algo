// https://practice.geeksforgeeks.org/problems/modified-numbers-and-queries0904/1





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


int sumOfAll(int l, int r)
{
    // code here
    vector<bool> list_of_prime(r+1,true);
    unordered_map<int ,set<int>>get_primes;


    for (int p = 2; p <= r; p++)
        if(list_of_prime[p])
            for (int num = 2*p; num <=r ; num+=p)
                list_of_prime[num] = false , get_primes[num].insert(p) ;

    
    int ans1 =0;
    for (int p = l; p<= r; p++)
        if(list_of_prime[p])
            ans1+=p ;
        else 
            for(auto x : get_primes[p])
                ans1+=x ;


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
    // long long int n ;//, target;
    // testcase=1 ;
    cin>>testcase;
    while (testcase--)
    {
        int n,m ;
        cin>>n>>m;
        cout<<sumOfAll(n,m)<<endl;

    }
    return 0 ;
}
