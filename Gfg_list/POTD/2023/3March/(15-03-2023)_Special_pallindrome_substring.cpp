



















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
    //Complete the function and return minimum number of operations
    public:
    bool isPalindrome(string s)
    {
        int start=0;
        int end=s.length()-1;
        while(start<=end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int specialPalindrome(string s1, string s2)
    {
        int finAns=INT_MAX;
        string temp=s1;
            for(int i=0;i<=s1.length()-s2.length();i++)
            {
                        //cout<<"i="<<i<<endl;
                //int i=1;
                int j=i;
                int ans=0;
                while(j-i<s2.length()){
                    if(s1[j]!=s2[j-i])
                    {
                        ans++;
                        s1[j]=s2[j-i];
                    }
                    j++;
                }
                // cout<<" s2 in s1 "<<s1.find(s2)<<endl;
                // cout<<"ans to accomodate s2 "<<ans<<endl;
                for(int k=0;k<s1.length()/2;k++)
                {
                        if(s1[k]!=s1[s1.length()-1-k])
                        {
                            if(k<i || k>=i+s2.length())
                                s1[k]=s1[s1.length()-1-k];
                            else if(s1.length()-1-k<i || s1.length()-1-k>=i+s2.length())
                                s1[s1.length()-1-k]=s1[k];
                            else
                                break;
                            ans++;
                        }
                }
                if(isPalindrome(s1))
                    finAns=min(finAns,ans);
            // cout<<"ans="<<ans<<endl;
                s1=temp;
            }
            if(finAns==INT_MAX)
                return -1;
        return finAns;
    }
};