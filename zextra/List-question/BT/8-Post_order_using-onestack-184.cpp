

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






vector<int> post_traversal(TreeNode* root)
{//left,right,value
    vector<int> ans1 ;
    stack<TreeNode*> s1 ;
    TreeNode *temp1 ;
    while (!s1.empty()||root!=NULL)
    {
        if(root!=NULL)
        {
            s1.push(root) ;
            root = root->left ;
        }
        else
        {
            temp1 = s1.top()->right ;
            if(temp1==NULL)
            {
                temp1 = s1.top() ;
                s1.pop();
                ans1.push_back(temp1->val) ;
                while (!s1.empty()&& temp1==s1.top()->right)
                {
                    temp1 =  s1.top() ;
                    s1.pop() ;
                    ans1.push_back(temp1->val) ;
                }
                

            }
            else
                root = temp1 ;
            
        }
        
    }
    return ans1 ;
    
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

    postorder = post_traversal(root);
    cout<<endl ;
    for (auto x : postorder)
        cout<<" "<<x;
    
    // inorder_n(ans);cout<<endl ;
    // preorder_n(ans);


    return 0;
}

