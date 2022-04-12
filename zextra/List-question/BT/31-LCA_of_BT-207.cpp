

// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1


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


bool findPath(Node *root , vector<int> &path, int k)
{
    if(root==NULL)
        return false;
    path.push_back(root->data);

    if(root->data == k)
        return true;

    if((root->left!=NULL&&findPath(root->left,path,k)) || (root->right && findPath(root->right,path,k)) )
        return true ;
    path.pop_back() ;
    return false ;
}
void search_1(Node *root , int LCA_val,Node* &ans1)
{
    if(root==NULL)
        return  ;
    if(root->data==LCA_val)
    {
        ans1 = root ;
        return ;
    }
    search_1(root->left,LCA_val,ans1);
    search_1(root->right,LCA_val,ans1);
}


Node* lca(Node* root ,int n1 ,int n2 )
{
    //Your code here 
    vector<int>path1 , path2 ;
    if (!findPath(root,path1,n1) ||!findPath(root,path2,n2) )
        return NULL ;

    int LCA_val,i1 ;
    for ( i1 = 0; i1 < path1.size()&&i1<path2.size(); i1++)
        if(path1[i1]!=path2[i1])    
            break ;
    LCA_val = path1[i1-1];
    Node *ans1 ;search_1(root,LCA_val,ans1);
    return ans1 ;
}



int main(int argc, char const *argv[])
{
    
    return 0;
}






