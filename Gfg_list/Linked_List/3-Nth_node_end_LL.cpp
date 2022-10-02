
// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/?page=1&category[]=Linked%20List&sortBy=submissions


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


//two pointer

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



int getNthFromLast(Node *head, int n)
{
       // Your code here
    int count1 = 0;
    Node *cur = head ;
    while(cur!=NULL)
    cur = cur->next , count1++ ;
    
    int i1 = 0 ;
    cur = head;
    if(count1<n)
    return -1;
    while(i1++<(count1-n))
    cur = cur->next ;
    
    return cur->data ;
}

