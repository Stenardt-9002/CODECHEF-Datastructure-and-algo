// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


int recursive(Node *cur)
{
    int carry=1;
    if(cur->next!=NULL)
        carry = recursive(cur->next);

    cur->data+=carry ;
    if(cur->data>=10)
    {
        cur->data=cur->data%10;
        return 1 ;
    }
    return 0 ;

}


Node* addOne(Node *head) 
{
    // Your Code here
    // return head of list after adding one
    if(head==NULL)
        return NULL ;
    int casrry = recursive(head);
    if(casrry!=0)
        {
            Node* newhead = new Node(casrry);
            newhead->next = head ;
            return newhead ;
        }
    return head ; 
}