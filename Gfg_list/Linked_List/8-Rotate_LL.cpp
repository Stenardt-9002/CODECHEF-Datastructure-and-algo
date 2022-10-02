// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1/?page=1&category[]=Linked%20List&sortBy=submissions#


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;






struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

Node* rotate(Node* head, int k)
{
    // Your code here
    if(k==0)
        return head ;
            
    Node* cur = head ;
    while(cur->next!=NULL)
        cur = cur->next ;

    cur->next = head ;
    cur = head ;

    for(int i1 = 0 ;i1<k-1 ; i1++)
        cur = cur->next ;

    head = cur->next ;
    cur->next = NULL ;
    return head  ;
}
