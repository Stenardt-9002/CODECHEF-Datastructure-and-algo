// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1





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




string decodedString(string s)
{
    // code here
    stack<char> s1 ;
    for (int i1 = 0; s[i1]; i1++)
    {
        if(s[i1]!=']')
            s1.push(s[i1]);
        else 
        {
            string temp = "";
            while(!s1.empty()&&s1.top()!='[')
            {
                temp = s1.top()+temp;
                s1.pop();
            }
            s1.pop();//remove [
            int count = 0;
            int power = 1 ;
            while(!s1.empty()&& (s1.top()>='0' &&s1.top()<='9'))
            {
                int num = s1.top()-'0';
                num = num*power ;
                power*=10 ;
                count+=num ;
                s1.pop();
            }
            // s1.pop();//remove count
            while(count--)
                for(auto c : temp)
                    s1.push(c);
        }
    }
    string ans1 = "";
    while(!s1.empty())
        ans1 = s1.top()+ans1,s1.pop();
    return ans1 ;
}






