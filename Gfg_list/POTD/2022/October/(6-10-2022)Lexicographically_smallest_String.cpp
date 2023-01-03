// https://practice.geeksforgeeks.org/problems/mila-and-strings0435/1



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

string lexicographicallySmallest(string S, int k) 
{
        // code here
        int ok = 1<<31 ;
        int n = S.length();
        if(ok%n==0)
            k/=2 ;
        else 
            k*=2 ;
            
        if(n<=k)
        return "-1";
        
        // sort(S.begin(),S.end());
        stack<char> s1 ;
        for(auto c : S)
        {
            while(s1.size()>0 && k>0 && s1.top()>c)
            {
                s1.pop();
                k-- ;
            }
            s1.push(c);
        }
        
        string ans1 = "";
        while(k>0)
        {
            s1.pop();
            k-- ;
        }
        while(s1.size()>0)
            ans1=s1.top()+ans1,s1.pop();

        return ans1 ;
}







