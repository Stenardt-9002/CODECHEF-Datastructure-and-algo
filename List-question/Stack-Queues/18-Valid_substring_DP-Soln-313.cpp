// https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/





#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;


int findMaxLen(string s) 
{
    int ans1 = 0;
    vector<int> dp1(s.length(),0)    ;
    for (int i1 = 0; i1 < s.length(); i1++)
    {
        if (s[i1]==')' && i1-dp1[i1-1]-1>=0 && s[i1-dp1[i1-1]-1]=='(')
        {
            dp1[i1] = dp1[i1-1]+2;
            if ((i1-dp1[i1-1]-2)>=0)
            {
                dp1[i1] += dp1[i1-dp1[i1-1]-2] ;
            }
            ans1 = max(dp1[i1],ans1);   
        }    
    }
    return ans1 ;
}


