// https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/



#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val ;
        left = right = NULL;
    }
} ;
 
void printInOrder(Node *node,vector<int> &traversal)
{
    if (node==NULL)
    {
        return ;
    }

    printInOrder(node->left,traversal);
    // cout<<" "<<node->data ;
    traversal.push_back(node->data);
    printInOrder(node->right,traversal);
}

void ModifyBT(Node *node,vector<int> traversal,int &index)
{
   if (node==NULL)
    {
        return ;
    }
    ModifyBT(node->left,traversal,index);
    node->data = traversal[index];
    index++ ;
    ModifyBT(node->right,traversal,index);
}

Node *BTtoBST(Node *node ,vector<int> traversal)
{
    sort(traversal.begin(),traversal.end());
    int index = 0;

    ModifyBT(node,traversal,index);

    return node;

}

int main(int argc, char const *argv[])
{

    Node *BTnode = new Node(10);
    BTnode->left = new Node(30) ;
    BTnode->right = new Node(15);
    BTnode->left->left = new Node(20) ;
    BTnode->right->right = new Node(5) ;

    vector<int> traversal ;
    Node *asn1 ;
    printInOrder(BTnode, traversal);
    asn1 = BTtoBST(BTnode,traversal);


    cout<<asn1->data<<endl;
    cout<<asn1->left->data<<endl; 
    cout<<asn1->right->data<<endl;
    cout<<asn1->left->left->data<<endl; 
    cout<<asn1->right->right->data<<endl;



    return 0;
}




