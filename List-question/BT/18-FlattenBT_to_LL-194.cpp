    
    // https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1/#



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


struct Node
{
    int key ; struct Node* left ; struct Node* right ;
};



Node* newNode(int val)
{
    Node* temp1 = new Node ;
    temp1->key = val ;
    temp1->left = NULL ;
    temp1->right = NULL ;

    return temp1 ;

}

    


    void flatten(Node *root)
    {
        //code here
        if(root==NULL ||(root->left == NULL && root->right==NULL))
            return  ;

        if(root->left!=NULL)
        {
            flatten(root->left) ;
            Node *temp1 = root->right ;
            root->right = root->left ;
            root->left = NULL ;
            Node *temp2 = root->right ;
            while(temp2->right!=NULL)
                temp2 = temp2->right ;
            temp2->right = temp1 ;
        }
        flatten(root->right);//all though use just set left subtree which was flatten on right side
    }