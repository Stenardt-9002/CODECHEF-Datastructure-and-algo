
// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1


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

 void inorder_tr(Node *tree,int &index,int &ans,int K)
    {
        if(tree==NULL)
        return ;
        
        // inorder_tr(tree->left,index,ans,K);
        inorder_tr(tree->right,index,ans,K);
        index+=1;
        
        if(index==K)
           ans = tree->data ;
        // inorder_tr(tree->right,index,ans,K);
        inorder_tr(tree->left,index,ans,K);
        
    }
    
    
    
    
    int kthLargest(Node *root, int K)
    {
        int ans,inex=0;
        inorder_tr(root,inex,ans,K-1);
        return ans;
        
    }



