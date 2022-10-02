// https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};


struct node* partition(struct node* head , struct node*end , struct node** newhead, struct node** newend)
{
    struct node* pivot = end ;
    struct node* prev = NULL , *cur = head , *tail = pivot ;

    //base case if head itself prblem 
    while (cur!=pivot)
    {
        if(cur->data < pivot->data)
        {
            if((*newhead)==NULL)
                (*newhead)=cur ;


            prev = cur ;
            cur = cur->next ;
        }
        else
        {
            if(prev)
                prev->next = cur->next ;
            
            struct node* temp = cur->next ;
            cur->next = NULL ;
            tail->next = cur  ;
            tail = cur ;
            cur = temp ;
        }
    }
    
    if((*newhead)==NULL)
        (*newhead) = pivot ;
    
    (*newend) = tail ;
    return pivot;
}


struct node* quickSort_recur(struct node *head , struct node *end ) 
{
    if(head==NULL || head==end )
        return head;
    node *newHead = NULL ;
    node *newEnd = NULL ;

    struct node* pivot = partition(head, end , &newHead , &newEnd );//slow will become new mid
    //partition will break 
    if(newHead != pivot)
    {
        struct node* tmp = newHead ;
        while(tmp->next != pivot )
            tmp = tmp->next ;
        tmp->next = NULL ;
        newHead = quickSort_recur(newHead , tmp );
        while(tmp!=NULL && tmp->next!=NULL)
            tmp = tmp->next ;
        tmp->next = pivot ;
    }
    pivot->next = quickSort_recur(pivot->next , newEnd);

    // fix_ptrs(start , ) ; //reverse sliw reverse and connect
    return newHead ;

}


void quickSort(struct node **headRef) 
{
    node* head1 = *headRef ;
    node* slow = *headRef ;
    if(slow==NULL || slow->next==NULL)
        return ;
    while(slow->next!=NULL)
        slow = slow->next;

    *headRef = quickSort_recur(head1 , slow) ;
    return ;


}
