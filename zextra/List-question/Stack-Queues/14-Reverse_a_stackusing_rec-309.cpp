// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;


void isnert_at_botom(stack<int> &st,int top1)
{
    int top2 ;
    if (st.size()==0)
        st.push(top1) ;//empty 
    else
    {
        top2 = st.top() ;
        st.pop() ;
        isnert_at_botom(st,top1) ;
        st.push(top2);
    }

}


void reverze(stack<int> &st)
{
    int top1 ;
    if (st.size()>0)
    {
        top1 = st.top() ;
        st.pop() ;
        
        reverze(st);
        isnert_at_botom(st,top1) ;

    }
    
}



int main(int argc, char const *argv[])
{

    stack<int> s1 ; 
    s1.push(1) ;
    s1.push(2) ;
    s1.push(3) ;
    s1.push(5) ;


    reverze(s1) ;

    while (!s1.empty())
    {
        cout<<s1.top();
        s1.pop()     ;
    }

    return 0;
}





