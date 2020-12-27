

#include<iostream>

using namespace std ; 


struct Node
{
    int data ;
    struct Node *left ;
    struct Node *right ;
    
};

struct Node * newNode(int data)
{
    struct Node* node = new Node ;
    node->data = data ;
    node->left = node->right = NULL ;
    return node;
}

void mirror(Node *root)
{
    if (root==NULL)
    {
        return  ;
    }
    queue<Node*> q1;


    q1.push(root);
    while (!q1.empty())
    {
        Node *curr = q1.front()        ;
        q1.pop();;
        swap(curr->left,curr->right);
        if (curr->left)
        {
            q1.push(curr->left);
        }
        
        if (curr->right)
        {
            q1.push(curr->right);
        }
        

    }
    







}

int main(int argc, char const *argv[])
{



    return 0;
}










