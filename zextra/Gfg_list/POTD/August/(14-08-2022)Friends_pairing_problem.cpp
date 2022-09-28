    
    

// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int countFriendsPairings(int n) 
{ 
    // code here
    int MOD = 1000000007 ;
    vector<int> dp1(n+1,0);
    dp1[1] = 1;
    dp1[2] = 2;
    for(int i1 = 3;i1<=n;i1++)
    {
        dp1[i1] = dp1[i1-1]%MOD+((i1-1)*dp1[i1-2]%MOD);
        if(dp1[i1]<0)
            dp1[i1]+=MOD;
    }
    
    return dp1[n];
    
}



int countFriendsPairings(int n) 
{ 
    // code here
    int MOD = 1000000007 ;
    vector<int> dp1(n+1,0);
    if(n==1)
        return 1 ;
    long long int a , b ,c ;
    a = 1 ;b = 2; 
    for(int i1 = 3;i1<=n;i1++)
    {
        c = (b+a*(i1-1))%MOD;
        a=b ;
        b=c ;
    }
    
    return b;
        
}
