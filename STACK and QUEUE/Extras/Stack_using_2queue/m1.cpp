
#include<iostream>
#include<queue>

using namespace std;





int main(int argc, char const *argv[])
{




    return 0;
}



void QueueStack :: push(int x)
{
        // Your Code
            q1.push(x);

}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code       
        
    if (q1.empty())
    {
        return -1; // empty stack
    }
    int x = q1.back();
    int sizeQ = q1.size();
    
    while (sizeQ>1)
    {
        sizeQ--;
        q2.push(q1.front());
        q1.pop();

    }
    //x = q2.front();
    q1.pop();
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();

    }

    return x;

    // return x;   
        
        
}
