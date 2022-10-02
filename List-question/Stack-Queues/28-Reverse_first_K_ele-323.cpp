// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;



queue<int> modifyQueue(queue<int> q, int k) 
{
    // add code here.
    queue<int> q2 ;
    stack<int> s1 ;
    for (int i1 = 0; i1 < k; i1++)
    {
        s1.push(q.front());
        q.pop() ;
    }
    for (int i1 = 0; i1 < k; i1++)
    {
        q2.push(s1.top());
        s1.pop() ;
    }
    while (!q.empty())
        {q2.push(q.front()); q.pop();}    

    return q2 ;
}


