// https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1
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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
      if(head==NULL||head->next==head)
        {
            *head1_ref = head ;
            if(!head)
            head->next = NULL ;
            *head2_ref = NULL ;
        }
    Node* slow1 = head ;
    Node* fast1 = head ;
    while(fast1->next!=head)
    {
        fast1 = fast1->next ;
        if(fast1->next!=head)
        {
            fast1 = fast1->next ;
            slow1 = slow1->next ;
        }
    }
    
    *head1_ref = head ;
    *head2_ref = slow1->next ;
    slow1->next = head ;
    fast1->next = *head2_ref ;

}

