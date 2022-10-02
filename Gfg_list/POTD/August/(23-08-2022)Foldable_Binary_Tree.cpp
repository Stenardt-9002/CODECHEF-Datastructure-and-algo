// https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1








#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
//Function to check whether a binary tree is foldable or not.



bool is_stuctre(Node* a ,Node* b)
{
    if(a==NULL && b==NULL)
        return true ;
    if(a!=NULL && b!=NULL && is_stuctre(a->left , b->left) && is_stuctre(a->right , b->right) )
        return true ;
    return false ;
}
void mirror_1(Node *node1)
{
    if(node1==NULL)
        return ;
    mirror_1(node1->left);
    mirror_1(node1->right);

    Node *swap1 = node1->left; 
    node1->left = node1->right ;
    node1->right = swap1 ;


}
bool IsFoldable(Node* root)
{
    // Your code goes here
    if(root==NULL)
        return true ;

    mirror_1(root->left);
    return is_stuctre(root->left , root->right);
    

    
}




