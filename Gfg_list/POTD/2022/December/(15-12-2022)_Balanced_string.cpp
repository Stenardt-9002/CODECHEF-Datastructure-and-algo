// https://practice.geeksforgeeks.org/problems/balanced-string1627/1


    










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






class Solution {
  public:
    int get_count(int N,int oric)
    {
        int n1 = oric ;
        int sum1 = 0 ;
        while(n1!=0)
        {
            sum1+=(n1%10);
            n1/=10 ;
        }
        if(sum1%2==0)
            return (N+1)/2;
        return (N-1)/2;
    }
    string BalancedString(int N) 
    {
        // code here
        string ans1 = "";
        int oric = N ;
        string orig = "abcdefghijklmnopqrstuvwxyz";
        if(N>=26)
        {
            int count = N/26 ;
            while(count--)
                ans1+=orig ;
            N-=(26*(N/26));
        }
        // if(N==0)
        //     return ans1 ;
        // cout<<"N "<<N<<endl;
        if(N%2==0)
        {
            int count = N/2 ;
            ans1 = ans1+orig.substr(0,count)+orig.substr(26-count,count);
        }
        else 
        {
            int count = get_count(N,oric);
            ans1 = ans1+orig.substr(0,count)+orig.substr(26-(N-count),(N-count));
        }
        return ans1 ;
    }
};


