// https://practice.geeksforgeeks.org/problems/8d0e8785cef59cf4903b926ceb7100bcd16a9835/1






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



class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr)
    {
        // Code here
        int cunt = 0 ;
        multiset<string> ahsh ; 
        for(int i = 0 ; i<n ; i++)
        {
            string temp = arr[i];
            reverse(temp.begin(),temp.end());
            if(ahsh.find(temp)==ahsh.end())
                ahsh.insert(arr[i]);
            else 
                ahsh.erase(temp);
            // debig(ahsh);
        }
        if(n%2==0)
            return ahsh.empty();
        if(ahsh.size()==1)
        {
            string tep = *(ahsh.begin());
            string tep2  = tep ;
            // cout<<tep2<<endl ; 
            reverse(tep2.begin(),tep2.end());
            return tep==tep2;
        }
        return false ;
    }
};











