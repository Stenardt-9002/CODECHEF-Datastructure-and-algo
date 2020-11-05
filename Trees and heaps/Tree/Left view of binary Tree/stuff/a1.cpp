#include<iostream>
#include<stdio.h>
#include<queue>






using namespace std;
  
struct node { 
    int data; 
    struct node *left, *right; 
}; 

struct node* newNode(int item) 
{ 
    struct node* temp = new node; 
    temp->data = item; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 


vector<int> leftViewUtil(struct node *root,queue<node*> &q)
{
    vector<int> answer1 ;
    if (root==NULL)
    {
        return answer1;
    }
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *temp1 = q.front();
        if (temp1)
        {
            answer1.push_back(temp1->data); //first data wait unitl null encounter
            
            //push all children 

            while (q.front()!=NULL)
            {
                if (temp1->right)
                {
                    q.push(temp1->left);
                }
                if (temp1->right)
                {
                    q.push(temp1->right);
                }
                q.pop(); //remove parent

                temp1 = q.front() ; // next iter temp1 children
                    
            }
            

            // done annother NULL MARk 
            q.push(NULL);


        }
        
        // remove last MARK delimiter 
        q.pop();

    }


    return answer1;
    
    


}



void leftView(struct node* root) 
{ 
    queue<node*> q; 
  
    leftViewUtil(root, q); 
} 




int main(int argc, char const *argv[])
{
     struct node* root = newNode(10); 
    root->left = newNode(12); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(5); 
    root->right->left->right = newNode(6); 
    root->right->left->right->left = newNode(18); 
    root->right->left->right->right = newNode(7); 



    return 0;
}












