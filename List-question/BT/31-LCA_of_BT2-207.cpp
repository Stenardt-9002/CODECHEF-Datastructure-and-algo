// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 




TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{

    if(root==NULL)
        return NULL ;

    if(root==p|| root==q)
        return root ;

    TreeNode *left = lowestCommonAncestor(root->left , p,q);
    TreeNode *right = lowestCommonAncestor(root->right , p,q);

    if(left!=NULL && right!=NULL)
        return root ;

    else if(left!=NULL)
        return left ;

    return right;
}



