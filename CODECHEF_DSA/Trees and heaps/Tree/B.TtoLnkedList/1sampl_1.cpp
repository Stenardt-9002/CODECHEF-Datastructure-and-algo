#include<iostream>

using namespace std;




class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};


// class LinedList{
//     public :
//     int data;
//     LinedList *left;
//     LinedList *right;
// };




node* newNode(int data)  
{  
    node* new_node = new node();  
    new_node->data = data;  
    new_node->left = new_node->right = NULL;  
    return (new_node);  
} 





node *Dllcoversion(node *root)
{
    if (root == NULL)
    {
        return root;
    }
    



    if (root->left)
    {
        node *x1 = Dllcoversion(root->left);


        //go to right end 
        for (; x1->right!=NULL  ; x1=x1->right)
        
        x1->right = root;
        // left to right lined list 

        root->left = x1;
        // right to left linked list
        
    }
    
    if (root->right)
    {
        node *y1 = Dllcoversion(root->right);


        //go to right end 
        for (; y1->left!=NULL  ; y1=y1->left)
        
        y1->left = root;
        // left to right lined list 

        root->right = y1;
        // right to left linked list
        
    }


    return root ;

}














int main(int argc, char const *argv[])
{
    node *root = newNode(10);  
    root->left = newNode(12);  
    root->right = newNode(15);  
    root->left->left = newNode(25);  
    root->left->right = newNode(30);  
    root->right->left = newNode(36);

    node *answr = Dllcoversion(root);


    return 0;
}









