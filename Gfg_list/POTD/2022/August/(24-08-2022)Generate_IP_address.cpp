// https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1








#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void recursiv_util(string s , int sta , int end , int depth , string cur , vector<string> &ans1)
{
    if(sta == (end+1)&& depth ==5)
        ans1.push_back(cur.substr(1));
    
    for(int k= sta ;  k<sta+3 && k<=end ; k++)
    {
        string newstr = s.substr(sta , k-sta+1);
        if(s[sta]=='0' && newstr.size()>1 || stol(newstr)>255)
            return ; 
        
        recursiv_util(s , k+1 , end , depth+1 , cur+"."+newstr , ans1);
    }

}
    vector<string> genIp(string &s) 
    {
        // Your code here
        vector<string> ans ;
        int n = s.size();
        recursiv_util(s, 0 , n-1 , 1 ,"" ,ans);
        return ans ;
    }


