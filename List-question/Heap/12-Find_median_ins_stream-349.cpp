// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);




class Solution
{
    
    public:
    //Function to insert heap.
    
    double median_val ;
    priority_queue<int,vector<int>> left_heap ;//elements that is small on left side median
    priority_queue<int,vector<int>,greater<int>> right_heap ;
    void insertHeap(int &x)
    {
        if(left_heap.size()==0 && right_heap.size()==0 )
        {
            median_val = x ;
            right_heap.push(median_val);
        }
        else 
        {
            if(right_heap.size()>left_heap.size())
            {
                if(x>median_val)//# x should go in right heap
                {
                    left_heap.push(right_heap.top());
                    right_heap.pop();
                    right_heap.push(x);
                }
                else 
                    left_heap.push(x);

                median_val = ((double)(left_heap.top()+right_heap.top()))/2.0;
            }
            else if (right_heap.size()<left_heap.size())
            {
                if(x<median_val)//# x should have gone to left heap
                {
                    right_heap.push(left_heap.top());
                    left_heap.pop();
                    left_heap.push(x);
                }
                else 
                    right_heap.push(x);

                median_val = ((double)(left_heap.top()+right_heap.top()))/2.0;
            }
            else //same size of both heap
            {
                if(x>median_val)
                {
                    right_heap.push(x) ;
                    median_val = (double)(right_heap.top());
                }
                else 
                {
                    left_heap.push(x) ;
                    median_val = (double)(left_heap.top());
                }
            }
        }
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        return median_val ;
    }
};





