
// https://practice.geeksforgeeks.org/problems/valid-substring0624/1


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
    stack<int> s1 ; s1.push(-1);
    int lenght = s.length();
    int count1 = 0;
    for (int i1 = 0; i1 < lenght; i1++)
    {
        if (s[i1]=='(')
            s1.push(i1) ;
        else
            if (!s1.empty())
                s1.pop()             ;

            if (!s1.empty())
                count1 = max(count1 , i1-s1.top()) ;

            else 
                s1.push(i1) ;
    }
    return count1 ;

}


