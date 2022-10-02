// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
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

    Node(int x){
        data = x;
        next = NULL;
    }

};

    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        struct Node* back_dummy = NULL ;
        struct Node* next_dummy = head ;
        while(head!=NULL)
        {
            next_dummy = next_dummy->next ; 
            head->next = back_dummy ; 
            back_dummy = head ;
            head = next_dummy ;
        }
        return back_dummy ;
    }