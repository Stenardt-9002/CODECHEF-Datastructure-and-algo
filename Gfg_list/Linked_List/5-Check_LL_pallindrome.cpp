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


bool isPlaindrome_Util(Node **left,Node *right)
{
    // Your code here
    if(right==NULL )
        return true ;

    bool var = isPlaindrome_Util(left,right->next);
    if(!var)
        return false ;

    bool var2 = (right->data == (*left)->data);
    *left = (*left)->next;
    return var2;
}


bool isPalindrome(Node *head)
{
    //Your code here
    return isPlaindrome_Util(&head,head);
}




