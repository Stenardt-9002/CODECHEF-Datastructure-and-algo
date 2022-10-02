
#include<iostream>
#include<stdio.h>
#include<stack>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    string str1;
    stack<int> s;
    stack<int> s11;

    int testcaes;
    cin>>testcaes;
    while (testcaes--)
    {
    cin>>str1;

    for (long unsigned ij = 0; ij < str1.length(); ij++)
    {

        if (str1[ij]=='{'|| str1[ij]=='['||str1[ij]=='(')
        {
            s.push(str1[ij]);
        }
        else if (str1[ij] == '}')
        {
            if (s.top()=='{')
            {
                s.pop();                
            }
        }
        else if (str1[ij] == ']')
        {
            if (s.top()=='[')
            {
                s.pop();                
            }
        }
        else if (str1[ij] == ')')
        {
             if (s.top()=='(')
            {
                s.pop();                
            }            
        }
        

    }
    
    if (s.empty())
    {
        cout<<"balanced\n";
    }
    else 
    {
        cout<<"not balanced\n";
    }
    // while (!s.empty())
    // {
    //     s.pop();
    // }
  
    s = s11;
    }
    return 0;
}



