// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int key)
    {data = key;}
};


int sumof_util(Node *root,int *height)
{
    if(root==NULL)
    {
        *height = 0;
        return 0;
    }

    int lh=0,rh = 0;

    int lsum = sumof_util(root->left,&lh);
    int rsum = sumof_util(root->right,&rh);

    *height = max(lh,rh)+1;
    int cur_sum ;
    if(rh>lh)
        cur_sum = root->data+rsum;
    else if (lh>rh)
        cur_sum = root->data+lsum;

    else 
        cur_sum = max(lsum,rsum)+root->data ;//same height therefore consider latger sum 

    return cur_sum ;
}



int sumOfLongRootToLeafPath(Node *root)
{
    if(root==NULL)
        return 0;

    // int lsum = sumOfLongRootToLeafPath(root->left);
    // int rsum = sumOfLongRootToLeafPath(root->right);

    // int cur_sum = max(lsum,rsum)+root->data ;
    // return cur_sum ;
    int hrigh1;
    return sumof_util(root, &hrigh1 );
    //code here
}


int main(int argc, char const *argv[])
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    root->left->right->left = new Node(6);

    cout<<sumOfLongRootToLeafPath(root)<<endl;
    return 0;
}



