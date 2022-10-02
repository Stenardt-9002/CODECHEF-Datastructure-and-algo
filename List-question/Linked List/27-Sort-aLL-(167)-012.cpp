// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

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
// Node* segregate(Node *head) {
    
//     // Add code her
//     if(head==NULL || head->next==NULL)
//         return head ;
        
//     Node *temp1 = new Node(-1) ;
//     temp1->next = head ;
//     Node* cur = temp1 ;   
//     Node *tail = head ;
//     while(tail->next!=NULL)
//         tail = tail->next ;
    
//     while(cur->next!=NULL && cur->next!=tail)
//     {
//         if(cur->next->data==0)
//         {
//             Node *newhead = cur->next ;
//             cur->next = cur->next->next;

//             newhead->next = temp1->next ;
//             temp1->next = newhead;
            
//         }
//         else if(cur->next->data==1)
//             cur = cur->next ;
//         // {
            
//         // }
//         else if(cur->next->data==2)
//         {
//             Node *curdata = cur->next ;
//             cur->next = cur->next->next;


//             Node *newtail = tail->next ;
//             tail->next = curdata ;
//             curdata->next = newtail ;
//         }

//     }
//     // if(cur->next !=NULL )
//     //     cur->next = cur->next->next ;
        
//     return temp1->next ;       
// }














    Node* segregate(Node *head) {
        
        // Add code here
        if(head==NULL || head->next==NULL)
            return head ;
            
        Node *tail = head ;
        Node *while_visited_end = NULL ;
        while(tail->next!=NULL)
            tail = tail->next ;
        
        Node* cur = head ;   
        if(cur->data == 2)
        {
            Node* tm1p = head->next ;
            head->next = NULL ;
            tail->next = head ;
            head = segregate(tm1p);
            return head;
        }
        tail->next= new Node(-1);
        while_visited_end = tail->next ;
        tail = tail->next ;

        
    
        while(cur->next!=NULL && cur->next!=while_visited_end)
        {
            if(cur->next->data==0)
            {
                Node *newhead = cur->next ;
                cur->next = cur->next->next;
                newhead->next = head ;
                head = newhead;
                
            }
            else if(cur->next->data==1)
                cur = cur->next ;
            // {
                
            // }
            else if(cur->next->data==2)
            {
                Node *curdata = cur->next ;
                cur->next = cur->next->next;
    
    
                Node *newtail = tail->next ;
                tail->next = curdata ;
                curdata->next = newtail ;
            }

        }
        if(cur->next !=NULL )
            cur->next = cur->next->next ;
            
        return head ;
        
    }







