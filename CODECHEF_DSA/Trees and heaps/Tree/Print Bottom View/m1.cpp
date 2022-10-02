#include<iostream>
#include<stdio.h>
#include<queue.h>

using namespace std;



struct Node
{
    int data ;  
    int hrizontaldata;
    Node *left ,*right ; 
};

Node* newNode(int val)
{
    Node *temp = new Node ;
    temp->data = val ;
    temp->left = temp->right = NULL ; 

    return temp ;
}

vector <int> bottomView(Node *root)
{
    vector<int> answer1 ; 
    if (root == NULL)
    {
        return ;
    }
    
    int indes = 0 ;

    map<int,int> m1 ; // horizontal disatnce value latest node data 

    queue<Node *> q1 ;
    root->hrizontaldata = indes ;
    q1.push(root);



    while (!q1.empty())
    {
        Node* test1 = q1.front();
        q1.pop() ; // remove las t element 
        indes = test1->hrizontaldata ; 
        m1[indes] = test1->data ; 
        if (test1->left!=NULL)
        {
            test1->left->hrizontaldata = indes-1 ; 
            q1.push(test1->left);
        }

        if (test1->right!=NULL)
        {
            test1->right->hrizontaldata = indes+1 ; 
            q1.push(test1->right);
        }



        
    }
    for (auto i1 = m1.begin(); i1 !=m1.end(); i1++)
    {
        answer1.push(i1->second);
    }
    
    return answer1;



}








int main(int argc, char const *argv[])
{




    return 0;
}




