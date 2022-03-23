// https://practice.geeksforgeeks.org/problems/construct-tree-1/1/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;
  Node(int data)
  {
    this->data = data ;
    this->left = this->right = NULL ;
  }
};
struct Node* newNode(int data)
{
    struct Node* node = new Node(data);
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}


Node *build_Tree_Util(int in[],int pre[],int ls,int re , unordered_map<int,int> hash_map1,int &cur_idx )
{
  if (ls>re)  
    return NULL ;

  int curr = pre[cur_idx++];
  Node *cen_node = newNode(curr) ;

  if(ls==re)  
    return cen_node ;

  int inIdx = hash_map1[curr] ;//no noeed to search
  cen_node->left = build_Tree_Util(in,pre,ls,inIdx-1,hash_map1,cur_idx);
  cen_node->right = build_Tree_Util(in,pre,inIdx+1,re,hash_map1,cur_idx);

  
  return cen_node ;
}


Node* buildTree(int in[],int pre[], int n)
{
    // Code here
    unordered_map<int,int> hasp1 ; 
    for (int i1 = 0; i1 < n; i1++)
        hasp1[in[i1]] = i1;

    int index1 = 0 ;
    return build_Tree_Util(in,pre,0,n-1,hasp1,index1)    ;
}


