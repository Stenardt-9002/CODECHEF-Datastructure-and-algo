// https://practice.geeksforgeeks.org/problems/reorder-list/1









#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;


struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


void reorderList(Node* head) 
{
    // Your code here
    if(head==NULL || head->next==NULL || head->next->next==NULL)
        return ;
        
    
    Node *slow = head , *fast = head ;
    while(fast!=NULL && fast->next!=NULL&& fast->next->next!=NULL)
    {
        slow = slow->next ;
        fast = fast->next->next ;
    }
    Node *prev = NULL , *curr = slow->next, *nexptr = slow->next ;
    // cout<<"DEbug "<<slow->data <<endl ;
    while(curr!=NULL)
    {
        nexptr = nexptr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = nexptr ;
    }
    slow->next = prev ;
        Node *first_ptr = head ;
        
    // while (slow->next!=NULL && slow->next->next!=NULL)
    while (slow->next!=NULL)
    {
        Node *savefirst = first_ptr->next ;
        Node *saveseoncd = slow->next ;
        slow->next = slow->next->next ;
        first_ptr->next = saveseoncd ;
        saveseoncd->next = savefirst ;
        first_ptr = savefirst;
        if(savefirst->next==NULL|| savefirst->next->next==NULL)
            return;
    }
}
