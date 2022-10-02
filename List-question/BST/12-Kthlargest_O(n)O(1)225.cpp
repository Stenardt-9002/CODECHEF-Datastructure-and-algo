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
            if (++count == k)
                Klargest = curr;
            curr = curr->left;
        }
        else 
        {
            Node* succ = curr->right;
            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;
 
            if (succ->left == NULL) 
            {

                succ->left = curr;
                curr = curr->right;
            }

            else 
            {
                succ->left = NULL;
                if (++count == k)
                    Klargest = curr;
 
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










