// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;



class StackQueue
{

public:

    stack<int> s1 ;
    stack<int> s2 ;
    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top())     ;
            s1.pop();
        }
        s1.push(x) ;
        while (!s2.empty())
        {
            s1.push(s2.top()) ;
            s2.pop() ;
        }
    }
    int pop()
    {
        if (s1.empty())
            return -1;
        int ans = s1.top() ;
        s1.pop() ;
        return ans ;
                
    }

    void print()
    {
        stack<int> temp = s1 ;
        while (!temp.empty())
            {
                cout<<" "<<temp.top();
                temp.pop() ;
            }
            cout<<endl;
    }


};



int main(int argc, char const *argv[])
{

    StackQueue s1 ; 
    s1.push(2) ;
    s1.print() ;
    s1.push(1) ;
    s1.print() ;
    s1.push(3) ;
    s1.print() ;
    s1.push(4) ;
    s1.print() ;
    s1.push(5) ;
    s1.print() ;
    cout<<"Popped "<<s1.pop()<<endl ;
    s1.print() ;


    return 0;
}



