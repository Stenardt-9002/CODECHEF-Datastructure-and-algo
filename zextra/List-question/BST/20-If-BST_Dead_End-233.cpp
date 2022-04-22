// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert( Node* node, int key)
{
    if (node == NULL)
        return new Node(key);
 
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}
bool isDeadUtil(Node *root , int min_val,int max_val)
{
    if(root==NULL)
        return false ;//fine
    bool left_ok = isDeadUtil(root->left,min_val,root->data-1);
    bool rigt_ok = isDeadUtil(root->right,root->data+1,max_val);
    
    return ((min_val>=max_val)||left_ok||rigt_ok);
}


bool isDeadEnd(Node *root)
{
    //Your code here
    if(root==NULL)
        return false ;
    return isDeadUtil(root,1,INT_MAX);
}

int main(int argc, char const *argv[])
{
    Node* root= new Node(8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    cout<<endl<<isDeadEnd(root)<<endl;
    return 0;
}
