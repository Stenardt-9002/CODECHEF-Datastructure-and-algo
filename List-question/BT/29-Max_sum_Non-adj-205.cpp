// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int key)
    {data = key;}
};


int getMax_Util(Node *root,map<Node*,int >&hash_map)
{

    if(root==NULL)
        return 0;
    //first search hash_map
    if(hash_map.find(root)!=hash_map.end())
        return hash_map[root];

    int included = root->data; 
    int excluded = 0 ;
    if(root->left!=NULL)
        included+=(getMax_Util(root->left->left,hash_map)+getMax_Util(root->left->right,hash_map));

    if(root->right!=NULL)
        included+=(getMax_Util(root->right->left,hash_map)+getMax_Util(root->right->right,hash_map));

    
    excluded+= (getMax_Util(root->left,hash_map)+getMax_Util(root->right,hash_map));
    hash_map[root] = max(excluded,included);
    return hash_map[root];
}





int getMaxSum(Node *root) 
{
    // Add your code here
    if(root==NULL)
        return 0;

    map<Node* , int >has_map ;
    return getMax_Util(root,has_map);
}


int main(int argc, char const *argv[])
{
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);
    // cout<<findLagestSubtree(root)<<endl;;
    return 0;
}





