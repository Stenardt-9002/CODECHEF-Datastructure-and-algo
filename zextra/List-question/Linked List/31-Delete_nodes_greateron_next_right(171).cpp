// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#include <bits/stdc++.h>
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


void recurs_ve(Node *left, int &max_valon_right )
{
    if(left->next==NULL)
        {
            max_valon_right= left->data ;
            return  ;
        }

    recurs_ve(left->next, max_valon_right);
    if(left->next->data<max_valon_right) 
        left->next = left->next->next ;

    max_valon_right = max(max_valon_right , left->next->data );
    return   ;
}


// Node *compute(Node *head)
// {
//     // your code goes here
//     if(head==NULL|| head->next == NULL)
//         return head ;
//     Node *cur = new Node(-1);
//     cur->next = head ;
//     // cur = head ;
//     int max_valon_right = INT_MIN ;
//     recurs_ve(cur , max_valon_right);
//     return cur->next ;
// }






Node *compute(Node *head)
{
    // your code goes here
    if(head==NULL|| head->next == NULL)
        return head ;
    Node *nextNode = compute(head->next);

    if(nextNode->data>head->data)
        return nextNode ;
    head->next = nextNode;
    return head ;
}





