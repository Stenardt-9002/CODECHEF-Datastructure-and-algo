    
    
    


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;






bool ispar(string x)
{
        // Your code here
    stack<char> s1 ;
    int length = x.size() ;
    for (int i1 = 0; i1 < length; i1++)
    {
        if (x[i1]=='{'||x[i1]=='('||x[i1]=='[')
            s1.push(x[i1]) ;

        else
        {
            if(x[i1]=='}')
                if (!s1.empty() && s1.top()=='{')
                    s1.pop() ;
                else
                    return false ;                
                    
                
            else if(x[i1]==']')
                if (!s1.empty() && s1.top()=='[')
                    s1.pop() ;
                else 
                    return false ;
                    
            else if(x[i1]==')')
                if (!s1.empty() && s1.top()=='(')
                    s1.pop() ;
                else 
                    return false ;        
        }

    }
    if (s1.empty())
        return true;
        
    
    return false ;
}


int main(int argc, char const *argv[])
{
    string var = "{([])}";
    var = "())({}";
    cout<<ispar(var) ;


    return 0;
}



