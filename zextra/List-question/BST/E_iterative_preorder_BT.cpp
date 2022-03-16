

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



int main(int argc, char const *argv[])
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


    stack<Node *> s1 ;
    Node *temp1 = root ;

    while (temp1!=NULL || !s1.empty())
    {
        while (temp1!=NULL)
        {
            cout<<temp1->data<<" "    ;
            
            if(temp1->right!=NULL)
                s1.push(temp1->right);

            temp1 = temp1->left ;
        }

        if (!s1.empty())
        {
            temp1 = s1.top() ;
            s1.pop();
        }
     
    }

    return 0;
}




