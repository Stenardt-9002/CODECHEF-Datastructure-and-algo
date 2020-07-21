#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left,*right;
    struct Node *newRight;
};

Node *newNode(int daat)
{
    Node *temp = new Node;
    temp->data = daat;
    temp->left = temp->right = temp->newRight = NULL;
    return temp;


}
//explain funckion 

/*
    Take node 
    for squeeze in queue
        pop and add its left and right children to queue 
        except left and add right connection to previous nodes
    
    last node popped add null to right 

*/



void connect(Node *p)
{

    queue<Node*> q ;
    q.push(p);
    int temp_siez;
    Node *prev;
        Node *temp1;     

    while (!q.empty())
    {
        temp_siez = q.size();   
        // cout<<q.size();
        // q.pop();
        for (auto i1j = 0; i1j < temp_siez; i1j++)
        {
            temp1 = q.front();
            q.pop();
            if (temp1->left!=NULL)
            {
                q.push(temp1->left);
            }

            if (temp1->right!=NULL)
            {
                q.push(temp1->right);
            }
            if (i1j>0)//except for first element
            {
                // temp1->newRight = prev;       
                prev->newRight = temp1;         
            }
            prev = temp1;

        }
        //last one 
        temp1->newRight =NULL;

    }
    //     delete temp1;
    // delete prev;

    // free(temp1);
    // free(prev);




}




int main(int argc, char const *argv[])
{
    Node *temp1;// = new Node(12);
    temp1 = newNode(10);
    temp1->left = newNode(8);    temp1->right = newNode(2);    
    temp1->left->left = newNode(3);



    connect(temp1);


    cout<<temp1->data<<" "<<temp1->newRight<<endl;
    cout<<temp1->left->data<<" "<<temp1->left->newRight->data<<" "<<temp1->left->newRight->newRight<<endl;
    cout<<temp1->left->left->data<<" "<<temp1->left->left->newRight;

    delete temp1->left->left;
    delete temp1->left;
    delete temp1->right;
    delete temp1;

    // free(temp1->left->left);
    // free(temp1->left);
    // free(temp1->right);
    // free(temp1);


    return 0;
}



