// https://practice.geeksforgeeks.org/problems/construct-tree-1/1/

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


TreeNode* build_tree_util(vector<int> preorder, vector<int> inorder,int start1 ,int end1 ,unordered_map<int,int> map_hash ,int &pred_index) 
{
    if (start1>end1)
        return NULL ;    

    int cure_node = preorder[pred_index++];
    TreeNode *cur_node = new TreeNode(cure_node);

    if (start1==end1)
        return cur_node;

    int iorder_index = map_hash[cure_node]     ;//get index 
    cur_node->left = build_tree_util(preorder,inorder,start1,iorder_index-1,map_hash,pred_index);
    cur_node->right = build_tree_util(preorder,inorder,iorder_index+1,end1,map_hash,pred_index);
    return cur_node ;

}








TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    int start1 = 0;
    int end = inorder.size();
    int preorder_index = 0;
    unordered_map<int,int> map_hash ; //for inorder node to index
    for (int i1 = 0; i1 < end; i1++)    //hashing
        map_hash[inorder[i1]] = i1 ;
    
    TreeNode* ans1 = build_tree_util(preorder, inorder,start1, end-1,map_hash,preorder_index) ;
    return ans1 ;
}


// struct Node
// {
//   int data;
//   Node* left;
//   Node* right;
//   Node(int data)
//   {
//     this->data = data ;
//     this->left = this->right = NULL ;
//   }
// };


// Node* buildTree(int in[],int pre[], int n)
// {
//     // Code here
//     set<Node*> set1 ;
//     stack<Node*> sta_ck1 ;
//     Node *root = NULL ;
//     for (int i1 = 0,j1=0; i1 < n; )
//     {
//         Node* curnode = NULL ;

//         do
//         {
//             curnode = new Node(pre[i1]);

//             if (root==NULL)
//                 root = curnode ;
//             if (sta_ck1.size()>0)
//             {
//                 if (set1.find(sta_ck1.top())!=set1.end())
//                 {
//                     set1.erase(sta_ck1.top()) ;
//                     sta_ck1.top()->right = curnode ;
//                     sta_ck1.pop() ;
//                 }
//                 else
//                     sta_ck1.top()->left = curnode ;
//             }
//             sta_ck1.push(curnode)         ;

//         } while (pre[i1++]!=in[j1]&&i1<n);
        
//         curnode = NULL ;
//         while (sta_ck1.size()>0 && j1<n && sta_ck1.top()->data==in[j1])
//         {   
//             curnode = sta_ck1.top() ;
//             sta_ck1.pop() ;
//             j1++ ;
//         }
        
//         if (curnode!=NULL)
//         {
//             set1.insert(curnode) ;
//             sta_ck1.push(curnode) ;
//         }

//     }
//     return root ;

// }







