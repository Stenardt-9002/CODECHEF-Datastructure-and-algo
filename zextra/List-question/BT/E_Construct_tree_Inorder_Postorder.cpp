









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





TreeNode* build_tree_util(vector<int> postorder, vector<int> inorder,int start1 ,int end1 ,unordered_map<int,int> map_hash ,int &pred_index) 
{
    if (start1>end1)
        return NULL ;    

    int cure_node = postorder[pred_index--];
    TreeNode *cur_node = new TreeNode(cure_node);

    if (start1==end1)
        return cur_node;

    int iorder_index = map_hash[cure_node]     ;//get index 
    cur_node->right = build_tree_util(postorder,inorder,iorder_index+1,end1,map_hash,pred_index);
    cur_node->left = build_tree_util(postorder,inorder,start1,iorder_index-1,map_hash,pred_index);
    return cur_node ;

}








TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) 
{
    int start1 = 0;
    int end = inorder.size();
    int preorder_index = end-1;
    unordered_map<int,int> map_hash ; //for inorder node to index
    for (int i1 = 0; i1 < end; i1++)    //hashing
        map_hash[inorder[i1]] = i1 ;
    
    TreeNode* ans1 = build_tree_util(postorder, inorder,start1, end-1,map_hash,preorder_index) ;
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

    // vector<int>preorder={1,2,4,6,5,7,8,9,10} ;
    vector<int>postorder={6,4,5,2,8,9,10,7,1} ;

    vector<int>inorder = {6,4,2,5,1,8,7,9,10};

    TreeNode* ans = buildTree(postorder,inorder);
    inorder_n(ans);cout<<endl ;
    preorder_n(ans);


    return 0;
}








// TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) 
// {
//     set<TreeNode*> se_t1 ;
//     stack<TreeNode*> stac1 ;
//     int n = postorder.size();
//     TreeNode* ans1 = NULL;
//     for (int pr = 0,in=0; pr < n;)
//     {
//         TreeNode *temp_node=NULL;
//         do
//         {
//             temp_node= new TreeNode(postorder[pr]);
//             if(ans1==NULL)  
//                 ans1 = temp_node ;
//             if(stac1.size()>0)
//             {
//                 if(se_t1.find(stac1.top())!=se_t1.end())//found
//                 {
//                     se_t1.erase(stac1.top());
//                     stac1.top()->right = temp_node ;
//                     stac1.pop();
//                 }
//                 else 
//                     stac1.top()->left = temp_node ;

//             }
//             stac1.push(temp_node);
//         } while (postorder[pr++]!=inorder[in]&& pr<n);
        

//         temp_node = NULL ;
//         while (stac1.size()>0 && in<n && stac1.top()->val == inorder[in])
//         {
//             temp_node = stac1.top();
//             stac1.pop();
//             in++ ;
//         }

//         if(temp_node!=NULL)
//         {
//             se_t1.insert(temp_node);
//             stac1.push(temp_node);
//         }

//     }
    
//     return ans1 ;


// }












