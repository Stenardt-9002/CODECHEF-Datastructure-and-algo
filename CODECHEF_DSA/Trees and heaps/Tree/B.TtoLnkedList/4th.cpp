
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



void BTTtoDLL(node *root,node* &head)  // head base address of pointer 
{
    if (root==NULL)
    {
        return ;
    }
    
    BTTtoDLL(root->right,head);
    root->right = head ;// previous head towards right
    
    if (head!=NULL) ///previous node is not null
    {
        head->left = root ; 
    }
    head = root ;
    BTTtoDLL(root->left,head);




}




//right extreme 
// return to head 
// right ->left is head 
// head is root




int main(int argc, char const *argv[])
{

    node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);


    node *head = NULL ;
    BTTtoDLL(root,head);

    cout<<endl ; 
    cout<<head->right->data<<" "<<head->right->right->data<<" "<<head->right->right->right->data<<" "<<head->right->right->right->right->data<<" ";




    return 0;
}



