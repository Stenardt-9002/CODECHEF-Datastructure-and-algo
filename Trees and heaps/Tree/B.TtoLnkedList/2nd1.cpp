#include<iostream>


class node
{
    
public:
    int data;
    node *left,*right;


};


node *BTTtoDLL(node *root)
{

}



node * newNode(int data)
{
    node * Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;


}





int main(int argc, char const *argv[])
{
    node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->left->right = newNode(35);



    // root = newNode(10);
    // root = newNode(10);
    node *head = BTTtoDLL(root);




    
    return 0;
}


















