

// https://practice.geeksforgeeks.org/problems/queue-reversal/1

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
#include<list>
#include<unordered_map>
#include<tuple>
using namespace std;


queue<int> recursion(queue<int> &q)
{
    if (q.empty())
        return q ;
    else 
    {
        int data = q.front() ;
        q.pop() ;
        recursion(q);
        q.push(data) ;
        return q ;
    }
}



queue<int> rev(queue<int> q)
{
    // return recursion(q) ;
    stack<int> s1 ;
    while (!q.empty())
    {
        s1.push(q.front()) ;
        q.pop() ;
    }
    while (!s1.empty())
    {
        q.push(s1.top()) ;
        s1.pop() ;
    }
    return q;
}


