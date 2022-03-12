// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};










Node* KthLargestUsingMorrisTraversal(Node* root, int k)
{
    Node* curr = root;
    Node* Klargest = NULL;
 
    int count = 0;
    while (curr != NULL) 
    {
        if (curr->right == NULL) 
        {
            // first increment count and check if count = k
            if (++count == k)
                Klargest = curr;
            // otherwise move to the left child
            curr = curr->left;
        }
        else 
        {
            // find inorder successor of current Node
            Node* succ = curr->right;
            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;
 
            if (succ->left == NULL) 
            {
                // set left child of successor to the
                // current Node
                succ->left = curr;
                // move current to its right
                curr = curr->right;
            }
            // restoring the tree back to original binary
            //  search tree removing threaded links
            else 
            {
                succ->left = NULL;
                if (++count == k)
                    Klargest = curr;
 
                // move current to its left child
                curr = curr->left;
            }
        }
    }
 
    return Klargest;
}




    
    
    int kthLargest(Node *root, int K)
    {
        
        int ans ;
        Node *curnode = KthLargestUsingMorrisTraversal(root,K);
        ans = curnode->data ;
        return ans;
        
    }










