


// https://stackoverflow.com/questions/45130465/inserting-at-the-end-of-stack

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;



void insert_At_end(stack<int> &s,int x)
{
    if (s.empty())
        {s.push(x) ; return ;}    
    else
    {
        int top1 = s.top() ;
        s.pop() ;
        insert_At_end(s,x) ;
        s.push(top1) ;
    }
}

void print_tack(stack<int> a)
{
    cout<<endl<<endl ;
    while (a.empty()==false)
    {
        cout<<a.top()<<endl ;
        a.pop() ;
    }
    cout<<endl<<endl ;
}

int main(int argc, char const *argv[])
{

    stack<int> s1 ; 
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    print_tack(s1);

    insert_At_end(s1, 0) ;
    print_tack(s1);


    return 0;
}


