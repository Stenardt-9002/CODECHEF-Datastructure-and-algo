// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
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



bool isHeap(struct Node* tree) 
{
    // code here

    queue<Node*> q1 ;
    q1.push(tree);
    bool we_are_done = false ;
    while (!q1.empty())
    {
        Node *temp = q1.front();
        q1.pop() ;
        if(temp->left!=NULL)
        {
            if(we_are_done ||(temp->left->data>temp->data))//max heap
                return false ;
            q1.push(temp->left);
        }
        else 
            we_are_done = true;

        if(temp->right!=NULL)
        {
            if(we_are_done||(temp->right->data>temp->data))
                return false ;
            q1.push(temp->right);
        }
        else 
            we_are_done = true ;
    }
    return true ;
}




