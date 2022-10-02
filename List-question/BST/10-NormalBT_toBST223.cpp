
// https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1/


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


Node *BST_vec(Node *root , vector<int> &arr1)
{
    if(root==NULL)
        return NULL ;
    BST_vec(root->left,arr1);
    arr1.push_back(root->data);
    BST_vec(root->right,arr1);

}



Node *construct_balanced_BST( vector<int> anas1,int star,int en1d)
{
    if (star>en1d)
    {
        return NULL ;
    }
    Node *root= NULL ;
    
    int mid1 = (star+en1d)/2;
    root = new Node(anas1[mid1]);
    root->left = construct_balanced_BST(anas1,star,mid1-1);
    root->right = construct_balanced_BST(anas1,mid1+1,en1d);
    return root ;

}


Node* buildBalancedTree(Node* root)
{
	//find inorder taversal
    //construct balanced BST from it
    if (root==NULL)
    {
        return NULL;
    }
    

    vector<int> asn1 ;
    BST_vec(root,asn1);
    int start = 0; int end = asn1.size();
    return construct_balanced_BST(asn1,start,end-1);
}










