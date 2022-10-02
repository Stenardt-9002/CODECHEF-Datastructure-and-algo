// https://practice.geeksforgeeks.org/problems/special-stack/1









#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;



stack<int> s2 ;


void push(stack<int>& s, int a)
{
	// Your code goes here
    int y ;
    if(s.empty()==true)
    {
        s.push(a) ;
        s2.push(a) ;
    }
    else
    {
        s.push(a) ;
        y = s2.top() ;
        // s2.pop();
        // s2.push(y) ;
        if (a<y)
            s2.push(a)  ;
        else 
            s2.push(y) ;
    }
}

bool isFull(stack<int>& s,int n)
{
	// Your code goes here
    return (s.size()==n) ;
}

bool isEmpty(stack<int>& s)
{
	// Your code goes here
    return s.empty() ;
}

int pop(stack<int>& s)
{
	// Your code goes here
    int x;
    if(s.empty()==false)
    {
        x = s.top()  ;
        s.pop() ;
        s2.pop() ;

        return x ;
    }
    return -1 ;
}

int getMin(stack<int>& s)
{
	// Your code goes here
    if (s.empty()==false)
    {
        return s2.top();
    }
    return -1;
}


int main(int argc, char const *argv[])
{

    stack<int> s1 ;
    int n ,temp1 ;
    // cin>>n ;
    // while (n--)
    // {
    //     cin>>temp1 ;
    //     // s1.push(temp1);
    //     push(s1,temp1);
    // }
    // // cout<<endl<<s2.top();
    // while (!s1.empty())
    // {
    //     cout<<" "<<s1.top()<<" "<<s2.top() <<"\n" ;
    //     s1.pop() ;
    //     s2.pop();
    // }
    
    

    push(s1,12);
    cout<<" "<<s1.top()<<" "<<getMin(s1) <<"\n" ;

    push(s1,13);
    cout<<" "<<s1.top()<<" "<<getMin(s1) <<"\n" ;
    push(s1,18);
    cout<<" "<<s1.top()<<" "<<getMin(s1) <<"\n" ;
    pop(s1);
    cout<<" "<<s1.top()<<" "<<getMin(s1) <<"\n" ;
    pop(s1) ;
    cout<<" "<<s1.top()<<" "<<getMin(s1) <<"\n" ;
    pop(s1) ;
    cout<<" "<<s1.top()<<" "<<getMin(s1) <<"\n" ;


    push(s1,11);
    cout<<" "<<s1.top()<<" "<<getMin(s1) <<"\n" ;

    push(s1,15);
    cout<<" "<<s1.top()<<" "<<getMin(s1) <<"\n" ;

    push(s1,9);
    cout<<" "<<s1.top()<<" "<<getMin(s1) <<"\n" ;

    push(s1,23);
    cout<<" "<<s1.top()<<" "<<getMin(s1) <<"\n" ;





    return 0;
}








