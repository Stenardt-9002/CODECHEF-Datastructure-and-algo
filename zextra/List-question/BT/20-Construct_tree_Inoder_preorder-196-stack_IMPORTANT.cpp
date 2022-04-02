// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



void viualise(int pre,int in,stack<TreeNode*> stac1,set<TreeNode*> se_t1,string DEBUG = "Debug-0")
{
    cout<<endl <<DEBUG;
    cout<<"pre "<<pre<<" in "<<in<<" stack " ;
    while (!stac1.empty())    
        {
            cout<<stac1.top()->val<<" ";
            stac1.pop();
        }
    cout<<endl ;
    cout<<"Sset";
    for (auto x :se_t1 )
    {
        cout<<" "<<x->val ;
    }
    
    cout<<endl;
}



TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    set<TreeNode*> se_t1 ;
    stack<TreeNode*> stac1 ;
    int n = preorder.size();
    TreeNode* ans1 = NULL;
    for (int pr = 0,in=0; pr < n;)
    {
        TreeNode *temp_node=NULL;
        do
        {
            temp_node= new TreeNode(preorder[pr]);

            if(ans1==NULL)  
                ans1 = temp_node ;
            if(stac1.size()>0)
            {
                if(se_t1.find(stac1.top())!=se_t1.end())//found
                {
                    se_t1.erase(stac1.top());
                    stac1.top()->right = temp_node ;
                    stac1.pop();
                }
                else 
                    stac1.top()->left = temp_node ;

            }
            stac1.push(temp_node);
        } while (preorder[pr++]!=inorder[in]&& pr<n);
        

        viualise(pr,in,stac1,se_t1,"DEBUG1");

        temp_node = NULL ;
        while (stac1.size()>0 && in<n && stac1.top()->val == inorder[in])
        {
            temp_node = stac1.top();
            stac1.pop();
            in++ ;
        }
        viualise(pr,in,stac1,se_t1,"DEBUG2");

        if(temp_node!=NULL)
        {
            se_t1.insert(temp_node);
            stac1.push(temp_node);
        }
        viualise(pr,in,stac1,se_t1,"DEBUG3");

    }
    
    return ans1 ;
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

    vector<int>preorder={1,2,4,6,5,7,8,9,10} ;
    vector<int>inorder = {6,4,2,5,1,8,7,9,10};

    TreeNode* ans = buildTree(preorder,inorder);
    inorder_n(ans);cout<<endl ;
    preorder_n(ans);


    return 0;
}

