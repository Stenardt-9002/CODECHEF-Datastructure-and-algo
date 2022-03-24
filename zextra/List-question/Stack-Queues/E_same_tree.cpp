// https://leetcode.com/problems/same-tree/

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


    bool isSameTree(TreeNode* p, TreeNode* q) 
    {          
       if(p==NULL||q==NULL)       
           return p==q ;
        return (p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right) );
        
    }

