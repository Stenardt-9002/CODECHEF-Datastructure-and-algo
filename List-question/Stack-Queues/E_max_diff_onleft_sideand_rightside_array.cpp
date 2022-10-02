// https://practice.geeksforgeeks.org/problems/maximum-difference-1587115620/1

























#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;




void print_Stack(stack<int> s1)
{
    cout<<endl;
    while (!s1.empty())
    {
        cout<<" "<<s1.top();s1.pop();
    }
    cout<<endl;
    
}


void print_vec(vector<int> a1)
{
    cout<<endl;
    for(auto x:a1)
        cout<<" "<<x;
}


int findMaxDiff(int A[], int n)
{
    //Your code here

    vector<int>rs(n,0) ;
    vector<int>ls(n,0) ;
    stack<int> s1 ;
    s1.push(0);
    for (int i1 = 1; i1 < n; i1++)
    {
        if (s1.empty()||A[s1.top()]<A[i1])
            s1.push(i1);
        else 
        {
            while (!s1.empty() &&A[s1.top()]>A[i1])
            {
                rs[s1.top()] = A[i1];
                s1.pop();
            }
            s1.push(i1);
        }

    }
    // cout<<endl ;
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cout<<" "<<rs[i1];
    // }
    
    while(!s1.empty())
        s1.pop();


    s1.push(n-1);
    for (int i1 = n-2; i1 >=0; i1--)
    {
        if (s1.empty()||A[s1.top()]<A[i1])
            s1.push(i1);
        else 
        {
            while (!s1.empty() &&A[s1.top()]>A[i1])
            {
                ls[s1.top()] = A[i1];
                s1.pop();
            }
            s1.push(i1);
        }
        // print_Stack(s1);
        // print_vec(ls) ;
    }
    // cout<<endl ;
    // for (int i1 = 0; i1 < n; i1++)
    // {
    //     cout<<" "<<ls[i1];
    // }
    int max1 = INT_MIN ;
    for (int i1 = 0; i1 < n; i1++)
    {
        max1 = max(max1 , abs(ls[i1]-rs[i1]));
    }
    
    return max1 ;
}



int main(int argc, char const *argv[])
{
    int n ; 
    cin>>n;
    int *ar1 = new int[n];
    for (int i1 = 0; i1 < n; i1++)
        cin>>ar1[i1]    ;
    cout<<findMaxDiff(ar1,n);
    delete []ar1 ;

    return 0;
}








