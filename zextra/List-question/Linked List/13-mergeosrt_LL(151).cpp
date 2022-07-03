// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};

void split_merge_list(Node* temphead, Node** firthalf, Node**secondhalf)
{
    Node *slow ,*fast;
    slow = temphead ;
    fast = temphead->next ;
    while (fast!=NULL)
    {
        fast = fast->next ;
        if(fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next ;
        }
    }
    *firthalf = temphead ;
    *secondhalf = slow->next;
    slow->next = NULL ;
}

Node* merge_fuc(Node* a, Node* b)
{
    Node* ans1 = NULL ;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a ;

    if(a->data<=b->data)
    {
        ans1 = a ;
        ans1->next = merge_fuc(a->next , b);
    }
    else 
    {
        ans1 = b;
        ans1->next = merge_fuc(a , b->next);
    }
    return ans1 ;
}


void merge_sort_util(Node** headTemp)
{
    Node* h1 = *headTemp ;
    Node* firsthalf ;
    Node* secondhalg ;
    if((h1==NULL)||(h1->next==NULL))
        return ;
    split_merge_list(h1,&firsthalf,&secondhalg);
    merge_sort_util(&firsthalf);
    merge_sort_util(&secondhalg);

    *headTemp = merge_fuc(firsthalf,secondhalg);
}


Node* mergeSort(Node* head) {
    // your code here
    merge_sort_util(&head);
    return head ;
}
