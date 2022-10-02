// https://leetcode.com/problems/invert-binary-tree/




#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;



using namespace std;


  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



TreeNode* Mirror_Util(TreeNode* node1)
{
    if(node1==NULL)
        return node1 ;

    TreeNode* swap1 ; 
    swap1 = node1->left ;
    node1->left = node1->right ;
    node1->right = swap1;

    if (node1->left!=NULL)
        node1->left = Mirror_Util(node1->left)    ;
    if (node1->right!=NULL)
        node1->right = Mirror_Util(node1->right)    ;
    return node1 ;
}

TreeNode* invertTree(TreeNode* root) 
{

    TreeNode *miror_tree ;
    miror_tree = Mirror_Util(root);
    return miror_tree ;
}

