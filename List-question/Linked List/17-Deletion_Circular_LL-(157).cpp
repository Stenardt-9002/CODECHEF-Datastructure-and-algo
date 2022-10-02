// https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};

void deleteNode(struct Node **head, int key)
{

// Your code goes here
    if(*head==NULL)
        return ;
    else if((*head)->data == key)
        *head  = (*head)->next ;
        
    Node *cur = *head ;
    while(cur->next!=NULL && cur->next->data!=key )
        cur = cur->next ;
    Node *find = cur->next ;
    cur->next = cur->next->next ;
    free(find);

}


 void reverse(struct Node** head_ref)
{

// Your code goes here
    Node *cur = *head_ref;
    if(cur==NULL && cur->next==cur )
        return ;

    Node* dummy = NULL ;
    Node* n2 = cur ; 
    while(cur->next!=*head_ref)
        cur = cur->next ;
    cur->next = NULL ; //break circular linked list     

    cur = *head_ref ;
    while(cur!=NULL)
    {
        n2 = n2->next;
        cur->next = dummy ;
        dummy = cur ;
        cur = n2 ;
    }

    (*head_ref)->next = dummy ;
    *head_ref = dummy ;
}




    // Node* cur = head ;
    // if(cur==NULL && cur->next==cur)
    //     return ;
        
    // Node* dummy = NULL ;
    // Node* n2 = cur ;
    // do
    // {
    //     n2 = cur->next ;
    //     cur->next = dummy ;
    //     dummy = cur ;
    //     cur = n2 ;
    // }
    // while(cur!=head);
    // head->next = dummy ;
    // return dummy ;

