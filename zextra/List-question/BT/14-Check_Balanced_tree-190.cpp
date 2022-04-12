// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1





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


//calulcate balanced along with height
bool isbalned(Node *root, int *height)
{
    if(root==NULL)
    {
        *height = 0;
        return true ;
    }
    int lefth=0,righth=0;
    bool left_side = isbalned(root->left,&lefth);
    bool rigt_side = isbalned(root->right,&righth);

    *height = max(lefth,righth)+1;
    if(abs(lefth-righth)>1)
        return false ;
    
    return left_side&&rigt_side;
}


bool isBalanced(Node *root)
{
    int height = 0;
    return isbalned(root,&height);
}

