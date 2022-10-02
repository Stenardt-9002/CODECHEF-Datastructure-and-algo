//    https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1


    

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


    

bool isIsomorphic(Node *root1,Node *root2)
{
//add code here.

    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false ;
    if(root1->data!=root2->data)
        return false ;

    return (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))||(isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left));
}






