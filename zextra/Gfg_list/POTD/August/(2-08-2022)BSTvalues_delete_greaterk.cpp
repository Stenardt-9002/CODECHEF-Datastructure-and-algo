

// https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

struct Node 
{
    int data;
    Node * right, * left;
};



Node* utill_delte(Node* temp , int k)
{
    if(temp==NULL)
        return NULL ;
    
    temp->left = utill_delte(temp->left , k) ;
    temp->right = utill_delte(temp->right , k);
    if(temp->data>=k)
    {
        Node *lechild = temp->left ;
        delete temp ;
        return lechild ;
    }
    return temp ;
}

Node* deleteNode(Node* root, int k)
{
    //Your code here
    root = utill_delte(root, k);
    return root ;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}

