


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;











class twoStack
{
private:
    int *arr ;
    int size ,top1,top2 ;
public:
    twoStack(int n=100);


    void push1(int x) ;
    void push2(int x) ;
    int pop1() ;
    int pop2() ;

};

twoStack::twoStack(int n=100)
{
    size = n; arr = new int[n] ; top1 =-1;top2= size ;
}




//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
    arr[++top1] = x;

}
   
void twoStacks ::push2(int x)
{
    arr[--top2] = x;
}
   
int twoStacks ::pop1()
{
    if(top1==-1)
        return -1 ;
    int data = arr[top1] ;
    top1-- ;
    return data ; 
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2==size)
        return -1 ;
    int data = arr[top2] ;
    top2++ ;
    return data ; 
}













