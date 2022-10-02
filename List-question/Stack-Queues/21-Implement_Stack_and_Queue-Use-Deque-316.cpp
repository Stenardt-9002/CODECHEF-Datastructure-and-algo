// https://www.geeksforgeeks.org/implement-stack-queue-using-deque/


#include <bits/stdc++.h>
using namespace std;
 
//Doubly Linked List
class DeqNode
{
public:

    int data ; 
    DeqNode *next,*prev ;
    DeqNode(int d)
    {
        data = d ; 
        next = NULL ;
        prev = NULL ;
    }
};


class Deque
{
    
public:
    DeqNode *head,*tail ;
    Deque()
        {head = tail = NULL ;}

    void insert_first(int x);
    void insert_last(int x);
    int delete_first() ;
    int delete_last() ;
};







