#include<iostream>


class node
{
    
public:
    int data;
    node *left,*right;


};

void Prevptrfix(node *root)
{

    static node *preptr1 = NULL;

    if (root!=NULL)
    {
        Prevptrfix(root->left);
        root->left = preptr1;
        preptr1 = root;
        Prevptrfix(root->right);

    }
    




}


node *Nextptrfix(node *root)
{

    node *prevvar = NULL;

    while (root && root->right!=NULL)
    {
        root = root->right;
    }
    
    while (root && root->left!=NULL)
    {
        prevvar = root;
        root = root->left;
        root->right = prevvar;
    }
    


    return root;

}









node *BTTtoDLL(node *root)
{

    Prevptrfix(root);

    return Nextptrfix(root);



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


















