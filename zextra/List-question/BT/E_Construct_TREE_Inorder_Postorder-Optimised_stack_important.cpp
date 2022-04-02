// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/






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


TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) 
{

    set<TreeNode*> se_t1 ;
    stack<TreeNode*> stac1 ;
    int n = inorder.size();
    int post_Index = n-1;


    TreeNode* ans1 = NULL;


    for (int post = n-1,i1=n-1; post >=0;)
    {
        TreeNode* node1 = NULL ;

        do
        {
            node1 = new TreeNode(postorder[post]);
            if(ans1==NULL)
                ans1=node1;

            if(stac1.size()>0)
            {
                if(se_t1.find(stac1.top())!=se_t1.end())
                {
                    se_t1.erase(stac1.top());
                    stac1.top()->left = node1;
                    stac1.pop();
                }
                else 
                stac1.top()->right = node1;
            }

        stac1.push(node1);

        } while (postorder[post--]!=inorder[i1]&& post>=0);
        
        node1 = NULL ;
        while (stac1.size()>0&& i1>=0 && stac1.top()->val==inorder[i1])
        {
            node1 = stac1.top();
            stac1.pop();
            i1--;
        }
        if (node1!=NULL)
        {
            se_t1.insert(node1);
            stac1.push(node1);
        }
        
    }

    return   ans1 ;
}


void inorder_n(TreeNode* node1)
{
    if(node1!=NULL)
    {
        inorder_n(node1->left);
        cout<<" "<<node1->val ;
        inorder_n(node1->right);
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







Node *buildTree(int in[], int post[], int n) 
{
    set<Node*> se_t1 ;
    stack<Node*> stac1 ;
    Node* ans1 = NULL;

    for (int pos = n-1,i1=n-1; pos >=0;)
    {
        Node* node1 = NULL ;

        do
        {
            node1 = new Node(post[pos]);
            if(ans1==NULL)
                ans1=node1;

            if(stac1.size()>0)
            {
                if(se_t1.find(stac1.top())!=se_t1.end())
                {
                    se_t1.erase(stac1.top());
                    stac1.top()->left = node1;
                    stac1.pop();
                }
                else 
                stac1.top()->right = node1;
            }

        stac1.push(node1);

        } while (post[pos--]!=in[i1]&& pos>=0);
        
        node1 = NULL ;
        while (stac1.size()>0&& i1>=0 && stac1.top()->data==in[i1])
        {
            node1 = stac1.top();
            stac1.pop();
            i1--;
        }
        if (node1!=NULL)
        {
            se_t1.insert(node1);
            stac1.push(node1);
        }
    }
    return ans1 ;
}











int main(int argc, char const *argv[])
{
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(7);
    // root->left->left= new TreeNode(4);
    // root->left->right= new TreeNode(5);
    // root->left->left->left= new TreeNode(6);

    
    // root->right->left = new TreeNode(8);
    // root->right->right = new TreeNode(9);
    // root->right->right->right = new TreeNode(10);

    // vector<int>preorder={1,2,4,6,5,7,8,9,10} ;
    vector<int>postorder={6,4,5,2,8,9,10,7,1} ;

    vector<int>inorder = {6,4,2,5,1,8,7,9,10};

    TreeNode* ans = buildTree(postorder,inorder);
    inorder_n(ans);cout<<endl ;
    preorder_n(ans);


    return 0;
}







