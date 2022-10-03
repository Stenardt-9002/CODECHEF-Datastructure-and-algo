#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef vector<int> vi ;
typedef vector<vi> vii ;

const int mod1 = (1e9+7);
const long long int mod2 =  1e18 ;

#define mii map<int,int> 
#define msi map<string,int> 
#define musi unordered_map<string,int> 

typedef  long long int lld;

int maxPizza(int n , int arr[])
{
    // code here.
    if(n==1)
        return arr[0];
    vector<int>dp1(n,0);
    dp1[0] = arr[0];
    dp1[1] = max(arr[1],dp1[0]);
    for (int i1 = 2; i1 < n; i1++)
        dp1[i1] = max(dp1[i1-2]+arr[i1] , dp1[i1-1]);
    return dp1[n-1];    
}

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


