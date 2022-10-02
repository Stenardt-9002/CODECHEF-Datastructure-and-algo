// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;



int prec(char c)
{
    if (c=='^')
        return 3 ;

    else if (c=='/'||c=='*')
        return 2;
    
    else if (c=='+'||c=='-')
        return 1;

    return -1;
}



string infixToPostfix(string s)
{
    // Your code here

    stack<char> s1 ;
    string an1 = "";
    int length = s.length();
    char currcha ;
    for (int i1 = 0; i1 < length; i1++)
    {
        currcha = s[i1];

        if ((currcha>='a'&&currcha<='z')|| (currcha>='A'&&currcha<='Z') || (currcha>='0'&&currcha<='9')  )
            an1+=currcha ;

        else if (currcha=='(')
            s1.push('(')        ;

        else if (currcha==')')
        {
            while (s1.top()!='(')
            {
                an1+=s1.top() ;
                s1.pop() ;
            }
            s1.pop() ;
        }
        
        else 
        {
            while (!s1.empty() || prec(s1.top())>=prec(s[i1]))
            {
                an1+=s1.top() ;
                s1.pop() ;
            }
            s1.push(currcha) ;
        }
    }


    while (!s1.empty())
    {
        an1+=s1.top() ;
        s1.pop() ;
    }
    return an1 ;



}


string infixToPostfix(string s)
{
    // Your code here
    int length = s.length() ;
    char curr ;
    stack<char> s1 ;
    string answer="" ;
    for (int i1 = 0; i1 < length; i1++)
    {
        curr = s[i1];
        if ((curr>='a' && curr<='z') || (curr>='A' && curr<='Z') || (curr>='0' && curr<='9')) 
            answer+=curr;        

        
        else if (curr=='(')
            s1.push(curr)        ;

        else if(curr==')')
        {
            while (s1.top()!='(')
            {
                answer+=s1.top();
                s1.pop();
            }
            s1.pop();
        }

        else
        {
            while (!s1.empty()&& prec(s[i1])<=prec(s1.top()) )
            {       
                answer+=s1.top() ;
                s1.pop();
            }   
            s1.push(curr) ;
        }

    }
    
    while (!s1.empty())
    {
        answer+=s1.top();
        s1.pop();
    }
    return answer ;
}


