

// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;



long long getMaxArea(long long arr[], int n)
{
    // Your code here
    stack<long long > s1;
    long long curarea= 0,max_area = 0,top1;
    for (int i1 = 0; i1 < n;)
    {
        if (s1.empty()|| arr[s1.top()]<arr[i1]  )
            s1.push(i1++)         ;//next

        else
        {
            top1 = s1.top() ;
            s1.pop() ;
            if(s1.empty())
                curarea = arr[top1]*i1 ;

            else
                curarea = arr[top1]*(i1-1-s1.top()) ;
            if (!s1.empty())
            cout<<"\nDEBUG1 "<<i1<<" "<<top1<<" "<<s1.top()<<" ";

            else 
            cout<<"\nDEBUG1 "<<i1<<" "<<top1<<" ";

            max_area = max(curarea,max_area) ;
        }
    }

    while (!s1.empty())
    {
        top1 = s1.top() ;
        s1.pop() ;
            if(s1.empty())
                curarea = arr[top1]*n ;

            else
                curarea = arr[top1]*(n-1-s1.top()) ;

        max_area = max(curarea,max_area) ;
    }
    return max_area ;    
    
}




int main(int argc, char const *argv[])
{
    long long *ar1;
    int i=0,n ;cin>>n;
    ar1 = new long long[n];
    long long temp1 ;
    while (n--)
    {
        cin>>temp1 ;ar1[i++]=temp1;
    }
    getMaxArea(ar1,i);
    return 0;
}


