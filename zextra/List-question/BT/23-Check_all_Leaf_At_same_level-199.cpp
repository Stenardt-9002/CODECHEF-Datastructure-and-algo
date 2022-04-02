// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
struct Node
{
    int data;
    Node* left;
    Node* right;
};




bool check_util(Node *root, int level , int &leaflevel)
{
    if(root==NULL)
        return true ; 

    if(root->left==NULL && root->right == NULL)
    {
        if (leaflevel==0)//first value
        {
            leaflevel= level ;
            return true ;        
        }
        return (level==leaflevel);
    }

    return (check_util(root->left,level+1 ,leaflevel)&&check_util(root->right , level+1,leaflevel));
}


bool check(Node *root)
{
    int level = 0,leaflevel =0 ;
    return check_util(root, level,leaflevel);
}






