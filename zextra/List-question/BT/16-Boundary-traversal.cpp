
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

void printLeftBndry(Node *tree1,vector<int> &answer)
{
    if (tree1==NULL)
    {
        return ;
    }
    
    // cout<<"\nHehehLeft\n";


    if (tree1->left)
    {
        // cout<<tree1->data<<" "; 

        answer.push_back(tree1->data)     ;
        printLeftBndry(tree1->left,answer);
    }
    else if (tree1->right)
    {
        // cout<<tree1->data<<" ";
        answer.push_back(tree1->data);
        printLeftBndry(tree1->right,answer);

    }
}

void printRightBndry(Node *tree1,vector<int> &answer)
{
    if (tree1==NULL)
    {
        return ;
    }
    


    if (tree1->right)
    {
        printRightBndry(tree1->right,answer);
        answer.push_back(tree1->data)     ;
        // cout<<tree1->data<<" ";

    }
    else if (tree1->left)
    {
        printRightBndry(tree1->left,answer);
        answer.push_back(tree1->data);
        // cout<<tree1->data<<" ";

    }
}


void printLeaves(Node *tree1,vector<int> &answer)
{
    if(tree1==NULL){return ;}
    // cout<<"\nHehehLeaves\n";
    printLeaves(tree1->left,answer) ;
    if (tree1->left==NULL && tree1->right==NULL)
    {
        answer.push_back(tree1->data);
        // cout<<tree1->data<<" ";

    }
    printLeaves(tree1->right,answer) ;
}



void boundary_traveral(Node *tree1, vector<int> &answer)
{
    if (tree1==NULL)
    {
        return ;
    }
    

    answer.push_back(tree1->data);
    // cout<<tree1->data<<" ";
    printLeftBndry(tree1->left , answer);
    printLeaves(tree1->left,answer) ;
    printLeaves(tree1->right,answer) ;
    printRightBndry(tree1->right,answer) ;


}






int main(int argc, char const *argv[])
{


    // Node* tree1 = newNode(10);
    // tree1->left = newNode(20) ;
    // tree1->right = newNode(30) ;
    // tree1->left->left = newNode(40) ;
    // tree1->left->right = newNode(60) ;




    Node* tree1 = newNode(20);
    tree1->left = newNode(8) ;
    tree1->right = newNode(22) ;
    tree1->left->left = newNode(4) ;
    tree1->left->right = newNode(12) ;
    tree1->left->right->left = newNode(10) ;tree1->left->right->right = newNode(14) ;
    tree1->right->right = newNode(25) ;



    vector<int> asnwer ;
    boundary_traveral(tree1,asnwer);
    cout<<endl;
    for (int i1 = 0; i1 < asnwer.size(); i1++)
    {
        cout<<asnwer[i1]<<" ";
    }
    




    return 0;
}
