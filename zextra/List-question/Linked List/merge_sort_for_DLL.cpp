// https://practice.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1/ 
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
};
struct Node *cut_infhalf(Node *first)
{
    Node *slow = first ;
    Node *fast = first ;
    while (fast->next && fast->next->next) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    Node *temp = slow->next; 
    slow->next = NULL; 
    return temp; 
}

// struct Node *merge_util(Node *first, Node *second)
// {
//     if(first==NULL)
//         return second ;
//     if(second == NULL)
//         return first ;

//     if(first->data<second->data)
//     {
//         first->next = merge_util(first->next , second);
//         first->next->prev = first ;
//         first->prev = NULL ;
//         return first ;
//     }
//     else 
//     {
//         second->next = merge_util(first , second->next);
//         second->next->prev = second ;
//         second->prev = NULL ;
//         return second ;
//     }

// }

struct Node *merge_util(Node *first, Node *second)
{
    if(first==NULL)
        return second ;
    if(second == NULL)
        return first ;

    Node *ans1 = NULL ;
    Node *cur = new Node(-1);
    ans1 = cur ;
    while(first!=NULL && second!=NULL)
    {
        if(first->data<second->data)
        {
            cur->next = first ;
            first->prev = cur  ;
            first = first->next ;
            // first->next->prev = first ;
        }
        else 
        {
            cur->next = second ;
            second->prev = cur ;
            second = second->next ;
        }

        cur = cur->next ;
    }
    
    while(first!=NULL)
    {
        cur->next = first ;
        first->prev = cur ;
        first = first->next ;
        cur = cur->next ;
    }
    while(second!=NULL)
    {
        cur->next = second ;
        second->prev = cur ;
        second = second->next ;
        cur = cur->next ;
    }

    ans1->next->prev = NULL ;
    return ans1->next ;
    
}

//Function to sort the given doubly linked list using Merge Sort.
struct Node *sortDoubly(struct Node *head)
{
	// Your code here
    if(head==NULL|| head->next ==NULL)
        return head ;

    Node *secondpart = cut_infhalf(head) ; //also break it 

    head = sortDoubly(head);
    secondpart = sortDoubly(secondpart);

    return merge_util(head, secondpart);
}
