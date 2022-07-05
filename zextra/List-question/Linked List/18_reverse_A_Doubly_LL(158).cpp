#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node* reverseDLL(Node * head)
{
    //Your code here
    Node* cur = head ;
    Node* temp ;
    if(cur==NULL || cur->next==NULL)
        return cur ;
    Node* pre1 ;
    while(cur!=NULL)
    {
        temp = cur->next ;
        cur->next = cur->prev ;
        cur->prev = temp ;
        pre1 = cur;
        cur  = cur->prev ;
    }

    return pre1 ;
}


