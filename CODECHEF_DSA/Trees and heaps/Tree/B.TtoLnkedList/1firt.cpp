#include<iostream>

using namespace std;


struct Node
{
    int data;
    Node *left,*right;
};


Node *newNode(int val)
{
    Node *temp1 = new Node;
    temp1->data = val;
    temp1->left = NULL;
    temp1->right = NULL;




}

void inorder(Node *rot)
{
    if (rot!=NULL)
    {
        inorder(rot->left);
        cout<<rot->data;
        inorder(rot->right);

    }
    
}




int main(int argc, char const *argv[])
{
    
    return 0;
}

Node * bToDLL(Node *root)
{
 
}

























