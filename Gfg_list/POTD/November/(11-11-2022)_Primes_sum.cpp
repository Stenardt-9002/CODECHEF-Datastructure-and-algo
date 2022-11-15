






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









bool allow_prime(int num)
{
    for(int i = 2 ; i*i<=num;i++)
        if(num%i==0)
            return false ;
    return true ;
}



class Solution 
{
public:
    string isSumOfTwo(int N)
    {
        // code here
        for(int i1 = 2 ; i1<=N/2;i1++)
        if(allow_prime(i1)&& allow_prime(N-i1))
            return "Yes" ;
        
        
        return "No";
    }
};