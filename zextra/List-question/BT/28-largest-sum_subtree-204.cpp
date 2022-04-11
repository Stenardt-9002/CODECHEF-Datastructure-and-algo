


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


int findLargestSum_util(TreeNode *root,int &ans1)
{
    if(root==NULL)
        return 0;
    int cur_sum = findLargestSum_util(root->left,ans1)+root->val+findLargestSum_util(root->right,ans1);
    ans1 = max(cur_sum,ans1);
    return cur_sum ;
}
int findLagestSubtree(TreeNode *root)
{
    if(root==NULL)
        return 0 ;

    int ans1 = INT_MIN ;
    findLargestSum_util(root,ans1);
    return ans1>0?ans1:0 ;
}







int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);
    cout<<findLagestSubtree(root)<<endl;;
    return 0;
}


