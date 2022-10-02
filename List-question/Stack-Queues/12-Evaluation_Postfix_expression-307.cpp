
// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1



#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;

void print_Stack(stack<int> s1 )
{
    // stack<int> s2 ;
    cout<<endl<<endl ;
    while (!s1.empty())
    {       
        // s2.push(s1.top());
        cout<<s1.top()<<endl;
        s1.pop() ;
    }
    cout<<endl<<endl;
}

int evaluatePostfix(string S)
{
    // Your code here

   int elngth = S.length();
            stack<int> s1 ;
            char curr ;
            int a ,b ;
            for (int i1 = 0; i1 < elngth; i1++)
            {
                curr = S[i1];
                if (isdigit(curr))
                    s1.push(curr-'0')         ;
                
                else
                {
                    if (curr == '*')
                        {
                            a = s1.top() ; s1.pop() ;
                            b = s1.top() ; s1.pop() ;
                            s1.push(a*b);
                        }      
                    else if (curr == '-')
                        {
                            a = s1.top() ; s1.pop() ;
                            b = s1.top() ; s1.pop() ;
                            s1.push(b-a);
                        }   
                    else if (curr == '+')
                        {
                            a = s1.top() ; s1.pop() ;
                            b = s1.top() ; s1.pop() ;
                            s1.push(a+b);
                        }   
                    else if (curr == '/')
                        {
                            a = s1.top() ; s1.pop() ;
                            b = s1.top() ; s1.pop() ;
                            s1.push(b/a);
                        }         
        
                }
            }
            return s1.top();

}

int main(int argc, char const *argv[])
{
    string S;
    cin>>S ;
    cout<<evaluatePostfix(S)<<endl;

    return 0;
}


