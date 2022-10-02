// https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/




#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;




bool ifRedundant(string str)
{
    stack<char> s1 ; 
    char top1 ;
    bool break_flag = true ;
    for (auto x : str)
    {
        if (x==')')
        {
            top1 = s1.top() ;
            s1.pop() ;

            break_flag = true ;
            //check if no operation only '(' bracket available )
            while (!s1.empty() && top1!='(' )
            {
                if (top1=='*'||top1=='/'||top1=='+'||top1=='-')
                    break_flag = false ;

                top1 = s1.top() ;
                s1.pop() ;
            }
            if(break_flag)
                return true ;
        }
        else 
            s1.push(x) ;
        
    }
    return false ;


}


