
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;


struct Node
{
    int data ; struct Node* left ; struct Node* right ;
};




Node* newNode(int val)
{
    Node* temp1 = new Node ;
    temp1->data = val ;
    temp1->left = NULL ;
    temp1->right = NULL ;

    return temp1 ;

}

bool isLeaf(Node* tree1)
{
    if (tree1!=NULL && tree1->left==NULL && tree1->right==NULL)
    {
        return 1 ;
    }
    return 0;
}


bool isSumtree(Node* tree1)
{
    int ls , rs ;
    if (tree1==NULL || isLeaf(tree1))
    {
        return 1 ; //a;l empty and single node tree are sum tree
    }
    if (isSumtree(tree1->left) && isSumtree(tree1->right) )
    {
        if (tree1->left == NULL)
        {
            ls = 0;
        }
        else if(isLeaf(tree1->left))
        {
            ls = (tree1->left->data);
        }   
        else
        {
            ls = 2*(tree1->left->data); // asuming sum trree else not in function call 
        }
        
        if (tree1->right == NULL)
        {
            rs = 0;
        }
        else if(isLeaf(tree1->right))
        {
            rs = (tree1->right->data);
        }   
        else
        {
            rs = 2*(tree1->right->data); // asuming sum trree else not in function call 
        }

        return (tree1->data == (ls+rs));

    }
    return 0 ;
    
    
    
}



int main(int argc, char const *argv[])
{


    // Node* tree1 = newNode(10);
    // tree1->left = newNode(20) ;
    // tree1->right = newNode(30) ;
    // tree1->left->left = newNode(40) ;
    // tree1->left->right = newNode(60) ;


    Node *root  = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    Node* tree1 = newNode(53);
    tree1->left = newNode(28) ;
    tree1->right = newNode(25) ;
    tree1->left->left = newNode(4) ;
    tree1->left->right = newNode(24) ;
    tree1->left->right->left = newNode(10) ;tree1->left->right->right = newNode(14) ;
    tree1->right->right = newNode(25) ;



    // vector<int> asnwer ;
    cout<<isSumtree(root);
    cout<<endl;
    cout<<isSumtree(tree1);

    // for (int i1 = 0; i1 < asnwer.size(); i1++)
    // {
    //     cout<<asnwer[i1]<<" ";
    // }
    




    return 0;
}

























