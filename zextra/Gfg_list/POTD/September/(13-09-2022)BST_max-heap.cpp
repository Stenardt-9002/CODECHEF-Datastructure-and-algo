// https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1









#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  struct Node {
      int data;
      Node *left;
      Node *right;
      Node() : data(0), left(nullptr), right(nullptr) {}
      Node(int x) : data(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
  };

vector<int> iterative_inorder(Node *node1)
{
    if (node1==NULL)
        return {};
    stack<Node *> s1 ;
    vector<int> ans1 ;
    Node *curr = node1 ;
    while (curr!=NULL || !s1.empty())
    {
        while (curr!=NULL)
        {
            s1.push(curr);
            curr = curr->left ;
        }
        
        curr = s1.top();
        s1.pop();
        ans1.push_back(curr->data);
        curr = curr->right ;
    }
    
    return ans1 ;

}
void BST_To_Heap(Node *root , vector<int>&arr , int *i )
{
    if(root==NULL)
        return ;
    BST_To_Heap(root->left , arr , i);
    BST_To_Heap(root->right , arr , i);
    root->data = arr[++*i];

}

void convertToMaxHeapUtil(Node* root)
{
    // Your code goes here
    int i1 = -1;
    vector<int> inorder_Traversal = iterative_inorder(root);
    BST_To_Heap(root , inorder_Traversal , &i1);
}    