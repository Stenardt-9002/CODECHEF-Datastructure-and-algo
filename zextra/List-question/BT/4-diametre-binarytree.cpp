


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

int height1(Node *root , int& ans)
{

    if (root==NULL)
    {
        return 0;
    }
    
    int left_height = height1(root->left, ans) ;
    int right_height = height1(root->right, ans) ;

    ans = max(ans, left_height+right_height+1) ; //keep updating diamtre for each node 
    return 1+max(left_height,right_height) ;



}




int diametre(Node* root)
{
    if (root==NULL)
    {
        return 0 ;
    }
    int ans = -9999 ;
    height1(root, ans );
    return ans ;//changing at address in function 
    

}



int main(int argc, char const *argv[])
{
    



    Node* tree1 = newNode(10);
    tree1->left = newNode(20) ;
    tree1->right = newNode(30) ;
    tree1->left->left = newNode(40) ;
    tree1->left->right = newNode(60) ;


    int x1 = diametre(tree1);
    cout<<x1;





    return 0;
}










