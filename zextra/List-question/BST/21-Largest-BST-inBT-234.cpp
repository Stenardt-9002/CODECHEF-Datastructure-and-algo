// https://practice.geeksforgeeks.org/problems/largest-bst/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



struct Return_type
{
    int size_val ,max_val , min_val,ans;    
    bool isBST ;
};


Node* insert( Node* node, int key)
{
    if (node == NULL)
        return new Node(key);
 
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

// bool largestBST_UTIL(Node *root,int &cur_he,int &ans ,int min_val,int max_val)
// {
//     if(root==NULL)
//         {
//             cur_he = 0;
//             ans = max(ans,cur_he);
//             return true ;
//         }
//     int left_nodes=0,right_nodes=0;
//     bool left_Ok = largestBST_UTIL(root->left , left_nodes ,ans, min_val , root->data-1);
//     bool right_Ok = largestBST_UTIL(root->right , right_nodes,ans ,root->data+1,max_val);
//     if(left_Ok&&right_Ok&&(root->data>=min_val)&&(root->data<=max_val))
//     {
//         cur_he = 1+left_nodes+right_nodes;
//         cout<<"\nDEBUG "<<cur_he<<endl ;
//         ans = max(ans,cur_he);
//         return true ;
//     }
//     // ans = max(ans,cur_he);
//     return false ;

// }

Return_type largestBST_UTIL(Node *root)
{
    if(root==NULL)
    {
        Return_type var ;
        var.size_val = 0;var.min_val = INT_MAX ; var.max_val = INT_MIN ;
        var.isBST = true ;var.ans = 0;
        return var ;
    }
    if(root->left==NULL && root->right == NULL)
    {
        Return_type var ;
        var.size_val = 1;var.min_val = root->data ; var.max_val = root->data ;
        var.isBST = true ;var.ans = 1;
        return var ;
    }
    
    // int left_nodes=0,right_nodes=0;
    Return_type left_Ok = largestBST_UTIL(root->left );
    Return_type right_Ok = largestBST_UTIL(root->right);
    Return_type ret_var ;
    ret_var.size_val = 1+left_Ok.size_val+right_Ok.size_val;

    if(left_Ok.isBST&&right_Ok.isBST&&left_Ok.max_val<root->data && right_Ok.min_val>root->data)
    {
        ret_var.min_val = min({left_Ok.min_val,right_Ok.min_val,root->data});
        ret_var.max_val = max({left_Ok.max_val,right_Ok.max_val,root->data});

        ret_var.ans = ret_var.size_val;
        ret_var.isBST = true ;
        return ret_var ;
    }
    ret_var.ans = max({left_Ok.ans,right_Ok.ans});
    ret_var.isBST = false ;
    return ret_var ;
    
}

int largestBst(Node *root)
{
    //Your code here
    int ans1 = INT_MIN ;
    // int cur_height = INT_MIN ;
    Return_type ret_var = largestBST_UTIL(root);
    return ret_var.ans ;
}
int main(int argc, char const *argv[])
{
    // Node* root= new Node(8);
    // root = insert(root, 5);
    // root = insert(root, 2);
    // root = insert(root, 3);
    // root = insert(root, 7);
    // root = insert(root, 11);
    // root = insert(root, 4);



    // Node* root= new Node(1);
    // root->left = new Node(4);
    // root->right = new Node(4);
    // root->left->left = new Node(6);
    // root->left->right = new Node(8);



    Node* root= new Node(6);
    root->left = new Node(6);
    root->right = new Node(3);
    // root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->right = new Node(8);

    root->right->right = new Node(3);
    root->right->left = new Node(9);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(2);



    cout<<endl<<largestBst(root)<<endl;
    return 0;
}



