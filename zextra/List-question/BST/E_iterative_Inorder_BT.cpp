


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
    while (!s1.empty()|| temp1!=NULL)
    {
        while (temp1!=NULL)
        {
            s1.push(temp1);
            temp1 = temp1->left ;
        }
        temp1 = s1.top() ;
        cout<<" "<<s1.top()->data<<" " ; 
        s1.pop() ;
        temp1 = temp1->right ;
     
    }
    



    return 0;
}



