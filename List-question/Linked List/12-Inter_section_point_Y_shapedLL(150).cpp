#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int count1 = 0 , count2 = 0;
    Node* cur1 = head1 ;
    Node* cur2 = head2 ;
    while (cur1!=NULL)
    {
        cur1 = cur1->next ;
        count1++ ;
    }
    while (cur2!=NULL)
    {
        cur2 = cur2->next ;
        count2++ ;
    }
    cur1 = head1 ;
    cur2 = head2 ;
    if(count1<count2)
    {
        cur1 = head2 ;
        cur2 = head1 ;
        std::swap(count1,count2);
    }

    int i1 = 0 ;
    while(i1++<count1-count2)
        cur1 = cur1->next;
    while(cur1!=cur2)
    {
        cur1 = cur1->next ;
        cur2 = cur2->next ;
    }
    if(cur1==NULL)
        return -1;
    return cur1->data ;

}

