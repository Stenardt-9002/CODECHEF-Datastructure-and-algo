

// https://practice.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node {
    struct Node* left, *right;
    int data;
};



Node *get_lca(Node *root , int first , int second )
{
    if(root==NULL)
        return NULL ;
    if(root->data == first || root->data == second)
        return root ;

    Node* left_lca = get_lca(root->left , first , second );
    Node* right_lca = get_lca(root->right , first , second );
    if(left_lca!=NULL && right_lca!=NULL)
        return root ;
    
    return (left_lca!=NULL)?left_lca:right_lca ;
}




bool dfs_util(Node *root , int data1 , bool tookaturn , int &ans1)
{
    if(root==NULL)
        return false ;

    if(root->data==data1)
        return true ;

    if(tookaturn)
    {
        if(dfs_util(root->left , data1 , tookaturn , ans1))
            return true ;
        if(dfs_util(root->right , data1 , !tookaturn , ans1))
        {
            ans1++ ;
            return true ;
        }
    }
    else 
    {
        if(dfs_util(root->right , data1 , tookaturn , ans1))
            return true ;
        if(dfs_util(root->left , data1 , !tookaturn , ans1))
        {
            ans1++ ;
            return true ;
        }
    }
    return false ;

}


int NumberOFTurns(struct Node* root, int first, int second)
{
    // Your code goes here
    Node *LCA = get_lca(root ,first ,second);
    if(LCA==NULL)
        return -1 ;

    int ans1 = 0 ;
    //go to LCA from both sides 
    if(LCA->data != first && LCA->data!=second)
    {
        if(dfs_util(LCA->right , second , false , ans1) || dfs_util(LCA->left , second , true , ans1))
         ;
        if(dfs_util(LCA->left , first , true , ans1) || dfs_util(LCA->right , first , false , ans1))
            ;
        return ans1+1 ;//1 common node 
    }
    else if(LCA->data==second)
    {
        dfs_util(LCA->right , first , false , ans1);
        dfs_util(LCA->left , first , true , ans1);
        
    }
    else
    {
        dfs_util(LCA->right , second , false , ans1);
        dfs_util(LCA->left , second , true , ans1);
        
    }
    return ans1 ; 
}




