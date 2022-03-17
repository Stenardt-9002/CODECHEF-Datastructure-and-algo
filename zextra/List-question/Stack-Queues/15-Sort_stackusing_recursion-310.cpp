

// https://practice.geeksforgeeks.org/problems/sort-a-stack/1

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;

void insert_at_rightpos(stack<int> &s , int val)
{
    int temp ;
    if (s.empty())
        s.push(val) ;

    else
    {
        if (s.top()>val)
        {
            temp = s.top() ;
            s.pop() ;
            insert_at_rightpos(s,val) ;
            insert_at_rightpos(s,temp);
        }
        else 
            s.push(val) ;
    }
}


void sort_Util(stack<int> &s)
{
    int top1 ;
    if (s.empty())
        return ;
    else
    {
        top1 = s.top() ;
        s.pop() ;
        sort_Util(s);
        insert_at_rightpos(s,top1) ;
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
    int n ;
    int tem1p;
    cin>>n;
    while (n--)
    {
        cin>>tem1p ;
        s1.push(tem1p) ;
    }
    print_tack(s1);
    sort_Util(s1) ;
    print_tack(s1);

    return 0;
}



