

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;




class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
    void print() ;
};




//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
        // Your Code
        arr[this->rear++] = x;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        int ans1 ; 
        // Your Code       
        if ((this->front)==(this->rear)&&(this->rear==0))
            return -1;
            
        else if(this->front+1==this->rear)
        {
            ans1 = arr[this->front] ;
            this->front = this->rear = 0;
        }
        else
        {
            ans1 = arr[this->front++] ;
        }
        
        return ans1 ;
}
void MyQueue::print()
{
    for (int i = front;i<rear   ;i++ )
        cout<<" " <<this->arr[i] ;
    cout<<endl ;
}


int main(int argc, char const *argv[])
{

    MyQueue a1 ;
    a1.push(2) ;
    a1.push(3) ;
    a1.print() ;

    cout<<a1.pop() ;
    a1.print() ;

    a1.push(4);
    a1.print() ;


    cout<<a1.pop();
    a1.print() ;

    return 0;
}
