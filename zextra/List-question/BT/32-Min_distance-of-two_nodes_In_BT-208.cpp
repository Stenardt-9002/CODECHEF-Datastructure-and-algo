

// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1



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



bool get_path(Node *root , int val,vector<int>&path1)
{
    if(root==NULL)
        return false;

    path1.push_back(root->data);
    if(root->data == val)
        return true ;

    if( (root->left!=NULL && get_path(root->left,val,path1) )||  (root->right!=NULL && get_path(root->right,val,path1) )  )
        return true;

    path1.pop_back();
    return false ;
}




int findDist(Node* root, int a, int b) 
{
    // Your code here
    vector<int>path1,path2 ;
    get_path(root,a,path1);
    get_path(root,b,path2);
    int i1=0;
    for ( i1 = 0; i1 < path1.size()&&i1<path2.size(); i1++)
        if(path1[i1]!=path2[i1])    
            break ;

    int distance = path1.size()+path2.size()-2*i1;
    return distance ;
}


int main(int argc, char const *argv[])
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(-6);
    // root->right->right = new Node(2);
    cout<<findDist(root,2,3)<<endl;;
    return 0;
}




