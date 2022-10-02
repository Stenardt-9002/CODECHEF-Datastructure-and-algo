

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

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



int height1(Node *tre1)
{
    if (tre1==NULL)
    {
        return 0 ;
    }
    else
    {
        int ledtph = height1(tre1->left);
        int redtph = height1(tre1->right);
        return max(ledtph,redtph)+1;
     
    }
    
    

}


int main(int argc, char const *argv[])
{
    



    Node* tree1 = newNode(10);
    tree1->left = newNode(20) ;
    tree1->right = newNode(30) ;
    tree1->left->left = newNode(40) ;
    tree1->left->right = newNode(60) ;


    int x1 = height1(tree1);
    cout<<x1;





    return 0;
}



























