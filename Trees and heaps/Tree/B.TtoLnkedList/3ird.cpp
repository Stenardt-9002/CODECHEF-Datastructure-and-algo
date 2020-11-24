
#include <iostream> 
using namespace std; 
  
/* A binary tree node has data, and left and right pointers */
struct node 
{ 
    int data; 
    node* left; 
    node* right; 
}; 


node* newNode(int data)
{
    node *newNode = new node ; 
    newNode->left = newNode->right = NULL; 
    newNode->data = data ;
    return newNode ; 

}


void BinaryTree2dll(node *root, node **head)
{
    if (root==NULL)
    {
        return  ; 
    }

    static node *prev = NULL ;  //when recursion starts keep saving them in 
    //head root
    BinaryTree2dll(root->left,head);
    if (prev == NULL)
    {
        *head = root ; 
    }
    else
    {
        root->left = prev ; 
        prev->right = root ; 
    }
    prev = root ;

    BinaryTree2dll(root->right ,head);


}







int main(int argc, char const *argv[])
{

    node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);











    return 0;
}









