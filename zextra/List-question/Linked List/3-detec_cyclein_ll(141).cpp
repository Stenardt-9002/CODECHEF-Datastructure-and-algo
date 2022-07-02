// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
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
    Node(int x) {
        data = x;
        next = NULL;
    }

};

    bool detectLoop(Node* head)
    {
        // your code here
        if(head==NULL||head->next==NULL)
            return false ;
        Node *slow = head ;
        Node *fast = head ;
        while(slow->next!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next ;
            if(slow==fast)
                return true ;
        }
        return false ;
    }