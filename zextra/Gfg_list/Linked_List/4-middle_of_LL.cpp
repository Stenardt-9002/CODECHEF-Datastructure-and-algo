// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1/?page=1&category[]=Linked%20List&sortBy=submissions#


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


int getMiddle(Node *head)
{
    // Your code here
    if(head==NULL )
        return -1 ;
    if(head->next==NULL)
        return head->data ;
    Node* slow = head ;
    Node* fast = head ;
    
    while(fast!=NULL)
    {
        fast = fast->next ;
        if(fast!=NULL)
        {
            slow = slow->next ;
            fast = fast->next ;
        }
    }
    return slow->data ;
}







