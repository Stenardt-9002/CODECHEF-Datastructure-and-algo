// https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/
// https://practice.geeksforgeeks.org/problems/array-to-bst4443/1/

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val ; left=right=NULL;
    }
};


Node *convertarrayto_bal_BST(vector<int> arr , int strat,int edn)
{
    if (strat>edn)
        return NULL ;

    int mid = strat+edn ; mid = mid/2;
    Node *root = new Node(arr[mid]);

    root->left = convertarrayto_bal_BST(arr,strat,mid-1);
    root->right = convertarrayto_bal_BST(arr,mid+1,edn);
    return root ;
}

void preorder_get(Node* temp1, vector<int> &arr  )
{
    if (temp1==NULL)
        return ;

    arr.push_back(temp1->data);
    preorder_get(temp1->left,arr);
    preorder_get(temp1->right,arr);
}


vector<int> sortedArrayToBST(vector<int>& nums) 
{
    vector<int> asn1 ;
    int start = 0 ;
    int end = nums.size();
    Node *ans1=convertarrayto_bal_BST(nums,start,end-1);
    preorder_get(ans1,asn1);
    return asn1;
}
