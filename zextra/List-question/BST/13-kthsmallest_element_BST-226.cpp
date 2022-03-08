
// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void Inorder_data_tra(Node *root,int &index,int &ans,int K)
{
    if(root==NULL)
        return  ;
    Inorder_data_tra(root->left,index,ans,K);
    index+=1 ;
    if (index==K)
    {
        ans = root->data;
    }
    Inorder_data_tra(root->right,index,ans,K);
}



int KthSmallestElement(Node *root, int K) 
{
    int index = 0;int ans=-1;
    Inorder_data_tra(root,index,ans,K);
    return ans ;
}
