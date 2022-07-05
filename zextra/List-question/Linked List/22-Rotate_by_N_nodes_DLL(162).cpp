
// https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1/
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};


Node *rotateDLL(Node *start,int p)
{
    //Add your code here
    Node *cur = start ;
    int i1 = 0;
    while(i1++<p&& cur!=NULL)
        cur = cur->next ;

    cur->prev->next = NULL;
    cur->prev = NULL ;

    Node *ans1 = cur ;
    while(cur->next!=NULL)
        cur = cur->next;

    cur->next = start;
    start->prev = cur ;
    return ans1 ;
}