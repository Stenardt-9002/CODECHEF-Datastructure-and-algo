
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1/?page=1&category[]=Linked%20List&sortBy=submissions

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;






struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};


Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* ans1 = new Node(-1);
    Node *orig = ans1 ;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<=head2->data)
        {
            ans1->next = head1;
            head1 = head1->next ;
        }
        else 
        {
            ans1->next = head2;
            head2 = head2->next ;
        }
        ans1 = ans1->next ;
    }
    while(head1!=NULL)
    {
        ans1->next = head1 ;
        head1 = head1->next ;
        ans1 = ans1->next ;
    }
    while(head2!=NULL)
    {
        ans1->next = head2 ;
        head2 = head2->next ;
        ans1 = ans1->next ;
    }
    
    return orig->next ;
}  

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    Node* ans1 = NULL;
    
    if(head1->data<=head2->data)
    {
        ans1 = head1; 
        ans1->next = sortedMerge(head1->next,head2);
    }
    else 
    {
        ans1 = head2; 
        ans1->next = sortedMerge(head1,head2->next);
    }   
        
    return ans1 ;
}
