#include "bits/stdc++.h"

using namespace std;




class node
{
    public:
    int data;
    node *left, *right;
};

node* newNode( int data )
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}



int LISS_count(node *rot1)
{
    if (rot1==NULL)
    {
        return 0 ;
    }
    
    int children_LISS = LISS_count(rot1->left)+LISS_count(rot1->right);

    int grandchilder = 1;//if node is include in independet set grandchildren are par
    if (rot1->left!=NULL)
    {
        grandchilder+=LISS_count(rot1->left->left)+LISS_count(rot1->left->right);
    }

    if (rot1->right!=NULL)
    {
        grandchilder+=LISS_count(rot1->right->left)+LISS_count(rot1->right->right);
    }
    
    return max(grandchilder,children_LISS);
}






























int main(int argc, char const *argv[])
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
 
    cout << "Size of the Largest"
         << " Independent Set is "
         << LISS_count(root);
 
    return 0;
}



























