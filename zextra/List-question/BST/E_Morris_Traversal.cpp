

// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/


// K th largest in BST using constant extra sapce 
// https://www.geeksforgeeks.org/kth-largest-element-bst-using-constant-extra-space/?ref=lbp
// https://www.geeksforgeeks.org/kth-smallest-element-in-bst-using-o1-extra-space/


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



void MorrisTraversal(Node* root)
{
    Node *curr , *pre ;
    if (root==NULL)
        return ;

    curr = root;    
    while (curr!=NULL)
    {
        if (curr->left==NULL)
        {
            cout<<" "<<curr->data<<" " ;
            curr = curr->right;
        }

        else
        {
            pre = curr->left ;
            //creating thread
            while (pre->right!=NULL && pre->right!=curr)
                pre = pre->right ;

            //if pre right == NULL end of line 
            if (pre->right==NULL)
            {
                pre->right = curr ;
                curr = curr->left ;
            }
            else
            {
                pre->right = NULL ;//setting tree original
                cout<<" "<<curr->data<<" ";
                curr = curr->right ;

            }
        }          
    }

}










int main(int argc, char const *argv[])
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);



    return 0;
}






