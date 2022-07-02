// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
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


void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
        if(head==NULL || head->next==NULL)
            return ;
        Node *slow = head ;
        Node *fast = head ;
        Node *first = head ; 
        Node *loopremoval = head ; 
        while(slow!=NULL && fast->next!=NULL &&fast->next->next!=NULL)
        {
            slow = slow->next ;
            fast = fast->next->next ;
            if(slow==fast)
            {
                if(fast==head)
                {
                    fast = head ;
                    while(fast->next!=head)
                    fast = fast->next ;
                    
                    fast->next=NULL;
                    return ;
                }
                loopremoval = NULL ;
                while(slow!=first)
                {
                    loopremoval = slow ;
                    slow = slow->next ;
                    first = first->next ;
                }
                loopremoval->next = NULL ;
                return ;
            }
        }
        return ; //no loop

}


