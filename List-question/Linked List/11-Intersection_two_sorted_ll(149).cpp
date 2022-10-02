

// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};



Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *cur1 = head1;
    Node *cur2 = head2;
    Node *ans1 = new Node(-1) ;
    Node *head = ans1 ;
    int data ;
    while(cur1!=NULL && cur2!=NULL )
    {
        if(cur1->data==cur2->data)
        {
            ans1->next = new Node(cur1->data);
            ans1 = ans1->next ;
            while(cur1->next!=NULL && cur1->data == cur1->next->data)
                cur1 = cur1->next ;
            cur1 = cur1->next ;

            while(cur2->next!=NULL && cur2->data == cur2->next->data)
                cur2 = cur2->next ;
            cur2 = cur2->next ;
            
        }
        else if(cur1->data>cur2->data)
            cur2 = cur2->next ;
        else 
            cur1= cur1->next;
    }
    return head->next ;
}