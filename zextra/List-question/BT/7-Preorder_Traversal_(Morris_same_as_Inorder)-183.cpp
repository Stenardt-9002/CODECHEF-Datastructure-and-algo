
// https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/

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

vector<int> getInorder(TreeNode* root)
{
    vector<int> Predorder1 ;
    TreeNode *cur = root ;
    TreeNode *prev =NULL;
    while (cur!=NULL)
    {
        if (cur->left==NULL)
        {
            Predorder1.push_back(cur->val);// is data 
            cur = cur->right ;
        }
        else
        {
            prev = cur->left;
            //make connection to left and right most children
            while (prev->right!=NULL && prev->right!=cur)
                prev = prev->right ;      

            // if already connected delte connection and go right freom original
            if(prev->right==cur)      
            {
                prev->right = NULL ;//delete 
                cur = cur->right ; //main node added now right node turn
            }
            //make conection and go left 
            else
            {
                prev->right = cur ;
                Predorder1.push_back(cur->val) ;//adding value in iorder traversal 

                cur = cur->left ;
            }
        }
    }
}


void preorder_n(TreeNode* node1)
{
    if(node1!=NULL)
    {
        cout<<" "<<node1->val ;
        preorder_n(node1->left);
        preorder_n(node1->right);
    }
}



int main(int argc, char const *argv[])
{
        TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->left->left->left= new TreeNode(6);

    
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    vector<int>postorder;
    // vector<int>inorder = {6,4,2,5,1,8,7,9,10};

    postorder = getInorder(root);
    cout<<endl ;
    for (auto x : postorder)
        cout<<" "<<x;
    
    // inorder_n(ans);cout<<endl ;
    // preorder_n(ans);


    return 0;
}






