
// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

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

    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     Node *cur = new Node(-1) ;
     cur->next = head ; 
     
     unordered_set<int> hash_map ; 
     while(cur->next!=NULL)
     {
        if(hash_map.find(cur->next->data)==hash_map.end())
            hash_map.insert(cur->next->data),cur = cur->next;
        else
            cur->next = cur->next->next ;
            
     }
     return head ; 
    }


