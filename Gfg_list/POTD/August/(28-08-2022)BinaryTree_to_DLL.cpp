// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


void BinaryTree2dll(Node *root, Node **head)
{
    if (root==NULL)
    {
        return  ; 
    }

    static Node *prev = NULL ;  //when recursion starts keep saving them in 
    //head root
    BinaryTree2dll(root->left,head);
    if (prev == NULL)
    {
        *head = root ; 
    }
    else
    {
        root->left = prev ; 
        prev->right = root ; 
    }
    prev = root ;

    BinaryTree2dll(root->right ,head);


}


void BToDLL(Node* root, Node*& head) 
{ 
    // Base cases 
    if (root == NULL) 
        return; 
    BToDLL(root->right, head); 
    root->right = head; 
    if (head != NULL) 
        head->left = root; 
  
    head = root; 
    BToDLL(root->left, head); 
} 
 
//  void BToDLL(Node* root, Node*& head) 
// { 
//     // Base cases 
//     if (root == NULL) 
//         return; 
  
//     // Recursively convert right subtree 
//     BToDLL(root->right, head); 
  
//     // insert root into DLL 
//     root->right = head; 
  
//     // Change left pointer of previous head 
//     if (head != NULL) 
//         head->left = root; 
  
//     // Change head of Doubly linked list 
//     head = root; 
  
//     // Recursively convert left subtree 
//     BToDLL(root->left, head); 
// } 
 

Node * bToDLL(Node *root)
{
    // your code here
        
    Node *head = NULL ; 
    BToDLL(root,head);
    return head ; 
}

