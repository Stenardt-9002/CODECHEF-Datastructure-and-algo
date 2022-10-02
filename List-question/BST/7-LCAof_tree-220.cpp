// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1/


#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val ;
        left = right = NULL;
    }
} ;
 

Node* LCA(Node *root, int n1, int n2)
{
   if (root==NULL)
   {
       return NULL;
   }
   if (root->data>n2 && root->data>n1 )
   {
       return LCA(root->left,n1,n2);
   }
   
   if (root->data<n2 && root->data<n1 )
   {
       return LCA(root->right,n1,n2);
   }
   return root;
}

Node *LCA(Node *root,int n1 , int n2)
{
    if (root==NULL)
        return NULL ;

    while (root!=NULL)
    {
        if (root->data>n1 && root->data>n2)
            root = root->left ;

        else if (root->data<n1 && root->data<n2)
            root = root->right;
        else 
            break;
    }
    return root;
}




