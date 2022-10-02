
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



Node *kthAncestorDFS(Node *root, int data,int &k,int &ans1)
{
    if(root==NULL)
        return NULL ;

    Node* temp = NULL ;

    if(root->data == data || (temp=kthAncestorDFS(root->left,data,k,ans1))||(temp=kthAncestorDFS(root->right,data,k,ans1)))
    {
        if(k>0)
            k-- ;

        else if(k==0)
        {
            ans1 = root->data ;
            return NULL ;
        }
        return root ;
    }
}


int main(int argc, char const *argv[])
{
        Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
 
    int k = 1;
    int node = 2;
 
    // print kth ancestor of given node
    int ans1 = -1 ;
    Node* parent = kthAncestorDFS(root,node,k,ans1);
    // check if parent is not NULL, it means
    // there is no Kth ancestor of the node
    cout<<ans1 ;
    // if (parent)
    //     cout << "-1";
    
    return 0;
}



