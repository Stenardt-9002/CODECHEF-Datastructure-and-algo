// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

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
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *removeDuplicates(Node *head)
{
 // your code goes here
    if(head==NULL||head->next==NULL)
        return head ;
    Node *cur=head ;
    while(cur!=NULL)
    {
        while(cur->next!=NULL && cur->data == cur->next->data)
            cur->next = cur->next->next ;
            
        cur = cur->next ;
    }
    return head ;
 
}