
#include<iostream>
#include<stdio.h>


using namespace std;
struct Node
{
    int data;
    Node *left ;
    Node *right ;

    Node(int val){
        data = val ;
        left = right = NULL ;
    }

};

int isBSTUtil(Node *node1,int min1 ,int max1)
{
    if (node1==NULL)
    {
        return 1;
    }

    if (node1->data<min1 || node1->data>max1)
    {
        return 0;
    }

    return isBSTUtil(node1->left,min1,node1->data-1) && isBSTUtil(node1->right,node1->data+1,max1);
    

    
}

bool isBST(Node *node1)
{
    isBSTUtil(node1,INT_MIN,INT_MAX);

}


int main(int argc, char const *argv[])
{


    return 0;
}





