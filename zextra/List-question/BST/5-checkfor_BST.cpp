// https://practice.geeksforgeeks.org/problems/check-for-bst/1



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


bool isBST_util(Node *root, Node * &prev)
{
    if (root==NULL)
        return true;
    
    if(!isBST_util(root->left , prev))
        return false ;

    if (prev!=NULL && root->data<=prev->data )
        return false ;    
    //not in ascending order 


    prev = root ;
    // now root is prev 

    if(!isBST_util(root->right , prev))
        return false;

    return true ;
}


bool isBST(Node *root)
{
    Node *prev = NULL ;
    return isBST_util(root,prev);
}




