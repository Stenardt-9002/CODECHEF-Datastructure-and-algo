// https://practice.geeksforgeeks.org/problems/quicksort-on-doubly-linked-list/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout


struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};
   
   
Node* partition(Node *l, Node *h){
    //Your code goes here
    int x = h->data; 
  
    Node *i = l->prev; 
  
    for (Node *j = l; j != h; j = j->next) 
    { 
        if (j->data <= x) 
        { 
            i = (i == NULL)? l : i->next; 
            swap(&(i->data), &(j->data)); 
        } 
    } 
    i = (i == NULL)? l : i->next; // Similar to i++ 
    swap(&(i->data), &(h->data)); 
    return i; 
}