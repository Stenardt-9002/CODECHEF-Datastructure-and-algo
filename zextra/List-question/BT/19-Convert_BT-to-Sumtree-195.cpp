// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1



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


bool isleaf(Node *node)
{
    return (node->left==NULL && node->right==NULL);
}



int sumtree_util(Node *node)
{
    if(node==NULL)
        return 0;

    int sum1_l = sumtree_util(node->left)    ;
    int sum1_r = sumtree_util(node->right)    ;

    int curs=0;
    if(isleaf(node))
    {
        curs = node->data ;
        node->data =0;
        return curs ;
    }
    else
    {
        curs = node->data ;

        node->data = sum1_l+sum1_r;
        return curs+node->data ;
        // if (node->left!=NULL)
        //     node->data += node->left->data;
        
        // if (node->right!=NULL)
        //     node->data += node->right->data;
    }
}


void toSumTree(Node *node)
{
    // Your code here
    if(node==NULL)
        return ;
    
    sumtree_util(node);
}


void inorder_n(Node* node1)
{
    if(node1!=NULL)
    {
        inorder_n(node1->left);
        cout<<" "<<node1->data ;
        inorder_n(node1->right);
    }
}


int main(int argc, char const *argv[])
{
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    inorder_n(root);
    toSumTree(root);
    cout<<endl;
    inorder_n(root);

    return 0;
}


