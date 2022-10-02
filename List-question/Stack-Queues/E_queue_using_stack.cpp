
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;




class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) 
    {
        while (!input.empty())
        {
            output.push(input.top()) ;
            input.pop() ;
        }
        
        input.push(x) ;

        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    int dequeue() 
    {
        int t ;
        if (!input.empty())
        {
            t = input.top() ;
            input.pop() ;
            return t ;
        }
        return -1;
    }
};


