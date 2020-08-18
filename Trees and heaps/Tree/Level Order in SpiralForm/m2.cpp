//zlternate traersal requires  two queu
#include<iostream>
#include<stack> 

using namespace std;

struct node {
    int data;
    struct node *left,*right;
};

struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void printSpiral(node *root)
{
    //Your code here
    
    if (root==NULL)
    {
        return ;   
        
    }
    
    stack<struct node*> s1;
    stack<struct node*> s2;
    
    s1.push(root);
    
    while(!s1.empty()||!s2.empty())
    {
        //alternzate stacks for each level and spiral form
        while(!s1.empty())
        {
            struct node* tem1p = s1.top();
            s1.pop();
            cout<<tem1p->data<<" ";
            
            if(tem1p->left)
            {
                s2.push(tem1p->left);
                
                
            }
            if(tem1p->right)
            {
                s2.push(tem1p->right);
                
                
            }
        }
        while(!s2.empty())
        {
            struct node* tem1p = s2.top();
            s2.pop();
            cout<<tem1p->data<<" ";
            
            if(tem1p->left)
            {
                s1.push(tem1p->left);
                
                
            }
            if(tem1p->right)
            {
                s1.push(tem1p->right);
                
                
            }
        }
        
    }
    
    
}



int main(int argc, char const *argv[])
{
        struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    cout << "Spiral Order traversal of binary tree is \n"; 
    printSpiral(root); 
    return 0;
}








