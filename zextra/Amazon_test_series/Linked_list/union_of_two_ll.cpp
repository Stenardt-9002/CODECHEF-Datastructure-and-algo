
// https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/0/?track=amazon-linkedlists&batchId=192
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>



using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};




struct Node* merge_uitl(struct Node *first1,struct Node *seocnd2)
{
    if(first1 == NULL)
        return seocnd2 ;

    if(seocnd2 == NULL)
        return first1 ;

    if(first1->data<=seocnd2->data)
    {
        first1->next = merge_uitl(first1->next,seocnd2);
        return first1;
    }
    else 
    {
        seocnd2->next = merge_uitl(first1,seocnd2->next);
        return seocnd2;
    }
}

struct Node* cutin_half(struct Node *head1)
{
    // Node *slow = head1 ;
    // Node *fast = head1 ;

    // while(fast!=NULL)
    // {
    //     fast = fast->next ;
    //     if(fast!=NULL)
    //     {
    //         slow = slow->next ;
    //         fast = fast->next ;
    //     }
    // }
    // fast = slow->next ;
    // slow->next = NULL ;
    // return fast ; 

    Node *slow = head1 ;
    Node *fast = head1 ;
    while (fast->next && fast->next->next) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    Node *temp = slow->next; 
    slow->next = NULL; 
    return temp; 
}


struct Node* merge_sort1(struct Node* head1)  
{
    if(head1==NULL||head1->next==NULL)
        return head1;
    Node *second = cutin_half(head1)  ;

    Node *first = merge_sort1(head1);
    second = merge_sort1(second);
    return merge_uitl(first , second );
}



struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    // code here
    // head1 = merge_sort1(head1);
    // head2 = merge_sort1(head2);
    if(head1==NULL && head2==NULL)
        return NULL ;
    Node *cur = head1;
    while(cur->next!=NULL)
        cur = cur->next ;

    cur->next = head2;
    head1 = merge_sort1(head1);
    if(head1==NULL||head1->next==NULL)
        return head1 ;
    cur = head1;
    //remove duplicates 
    while(cur!=NULL)
    {
        while(cur->next!=NULL && cur->data == cur->next->data)
            cur->next = cur->next->next ;
        cur = cur ->next ;
    }

    return head1 ;

    // while(head1!=NULL && head2!=NULL)
    // {
    //     if(head1->data<head2->data)
    //     {
    //         cur->next = head1 ;
    //         head1 = head1->next ;
    //     }
    //     else if(head1->data>head2->data)
    //     {
    //         cur->next = head2 ;
    //         head2 = head2->next ;
    //     }
    //     else 
    //     {
    //         if(cur->data==head1->data)
    //         {
    //             while(head1->next!=NULL && head1->data==head1->next->data)
    //                 head1 = head1->next ;

    //             while(head2->next!=NULL && head2->data==head2->next->data)
    //                 head2 = head2->next ;
    //         }
    //         else 
    //         {
    //             head1 = head1->next ;
    //             head2 = head2->next ;
    //         }
    //     }
    //     cur = cur->next ;
    // }

}
    


