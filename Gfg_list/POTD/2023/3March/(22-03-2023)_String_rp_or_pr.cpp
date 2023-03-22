











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



// long long int recursion_util(int X,int Y, string S , unordered_map<string,long long> &dp1)
// {
//     vector<int> indexprX,indexrpY ;
//     if(dp1.find(S)!=dp1.end())
//         return dp1[S];
//     int n = S.length();
//     if(n==0)
//         return 0 ;
//     for (int i = 0; i < n-1; i++)
//         if(S[i]=='r' && S[i+1]=='p')
//             indexprX.push_back(i);
//         else if(S[i]=='p' && S[i+1]=='r')
//             indexrpY.push_back(i);
        
//     if(indexprX.size()==0 && indexrpY.size()==0)
//         return dp1[S] = 0 ;

//     long long int ans = -1 ;
//     for (int vec : indexprX)
//     {
//         string temp = S.substr(0,vec)+S.substr(vec+2 , n-vec-2);
//         ans = max(ans , X+recursion_util(X,Y , temp , dp1));
//     }
//     for (int vec : indexrpY)
//     {
//         string temp = S.substr(0,vec)+S.substr(vec+2 , n-vec-2);
//         ans = max(ans , X+recursion_util(X,Y , temp , dp1));
//     }
//     return dp1[S] = ans ;

// }


// class Solution{   
// public:
//     long long solve(int X,int Y,string S)
//     {
//       //code here
//         unordered_map<string,long long> dp1 ;
//         recursion_util(X,Y,S,dp1);
//         dp1[""] = 0 ;
//         return dp1[S];
//     }
// };


string character_Del(char c1 , char c2 , ll &ans ,string S)
{
    string temp ; 
    for(auto x : S)
        if(!temp.empty() && temp.back()==c1 && x==c2)
        {
            temp.pop_back();
            ans++ ;
        }
        else 
            temp+=x ;
    return temp ;
}


class Solution{   
public:
    long long solve(int X,int Y,string S)
    {
      //code here
        ll cnt1 = 0 , cnt2 = 0 ;
        char c1 = 'p' ,c2 = 'r';
        if(X<Y)
            swap(c1,c2);
        string temp = character_Del(c1,c2 , cnt1 , S);
        character_Del(c2,c1 , cnt2 , temp);

        if(X<Y)
            return cnt1*Y+cnt2*X ;
        return cnt1*X+cnt2*Y ;
    }
};








