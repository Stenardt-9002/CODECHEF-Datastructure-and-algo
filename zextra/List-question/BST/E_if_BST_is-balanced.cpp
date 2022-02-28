
// https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val ;
        left = right = NULL;
    }
} ;
 

// bool isBalaned(Node *root , int *height)
// {
//     int lh = 0,rh = 0;
//     int l=0,r=0;
//     if (root==NULL)
//     {
//         *height = 0;return 1 ;//balanced
//     }
    
//     l = isBalaned(root->left,&lh);
//     r = isBalaned(root->right,&rh);


//     *height = max(lh,rh)+1 ;//current height
//     if (abs(lh-rh)>1)
//     {
//         //error 
//         return 0 ;//not balanced
//     }
//     else
//     {
//         if (l==1&&r==1)
//         {
//             return 1 ;
//         }
//         return 0;// not balanced
        
//     }
// }


//linear

bool isbalned(Node *root , int *height)
    {
        if(root==NULL)
        {
            *height = 0;//NULL
            return 1 ;//balanced
        }
        
        int leftbalnced =0,rightbalnced=0;
        int lefth=0,righth=0 ;
        
        leftbalnced = isbalned(root->left, &lefth);
        rightbalnced = isbalned(root->right, &righth) ;
        
        *height = max(lefth,righth)+1;
        if(abs(lefth-righth)>1)
        {
            return 0 ;
        }
        else
        {
            return (leftbalnced&&rightbalnced);
        }
    }

    bool isBalanced(Node *root)
    {
        int height = 0;
        return isbalned(root,&height);
    }




