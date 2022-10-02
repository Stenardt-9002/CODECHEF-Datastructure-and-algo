


// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;




int celebrity(vector<vector<int> >& M, int n) 
{
    // code here 
  
    stack<int>s1 ;
    for (int i1 = 0; i1 < n; i1++)
        s1.push(i1)     ;

    int first,second ;
    while (s1.size()>1)
    {
        first = s1.top() ;
        s1.pop() ;
        second = s1.top() ;
        s1.pop() ;
        //second is celebnrity
        if (M[first][second])
            s1.push(second);

        else    
            s1.push(first);
    }

    if (s1.empty())
        return -1 ;

    first = s1.top() ;
    s1.top() ;
    for (int i1 = 0; i1 < n; i1++)
        if (i1!=first && (M[i1][first]==0 || M[first][i1]==1))
            return -1 ;

    return first ;
}












