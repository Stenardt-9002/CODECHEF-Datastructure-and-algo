
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


void diagnolUtil(Node *root, int d ,map<int,vector<int>> &var1 )
{
    
    if (root==NULL)
        return ;
    
    var1[d].push_back(root->data) ;
    diagnolUtil(root->left,d+1,var1) ;
    diagnolUtil(root->right,d,var1) ;
}



vector<int> diagnolList(Node *root)
{
    vector <int> sasnwer ;
    map<int,vector<int>> var1 ;
    diagnolUtil(root,0,var1) ;
    for (auto it : var1)
        for (auto it2 : it.second  )
            sasnwer.push_back(it2);

    return sasnwer;
}





int main(int argc, char const *argv[])
{



    Node* tree1 = newNode(8);
    tree1->left = newNode(3) ;
    tree1->right = newNode(10) ;
    tree1->left->left = newNode(1) ;
    tree1->left->right = newNode(6) ;
    tree1->right->right = newNode(14) ;
    tree1->right->right->left = newNode(13) ;
    tree1->left->right->left = newNode(4) ;
    tree1->left->right->right = newNode(7) ;


    vector<int> x1 = diagnolList(tree1);
    cout<<endl;
    for (auto i1 : x1)
    {
        cout<<" "<<i1 ;
    }
    return 0;
}









