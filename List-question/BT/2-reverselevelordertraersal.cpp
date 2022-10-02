

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







int main(int argc, char const *argv[])
{

    Node* tree1 = newNode(10);
    tree1->left = newNode(20) ;
    tree1->right = newNode(30) ;
    tree1->left->left = newNode(40) ;
    tree1->left->right = newNode(60) ;


    queue<Node *> g  ;
    vector<int> gdata  ;
    Node *temp1 ; 
    g.push(tree1);
    while (!g.empty())
    {
        temp1 = g.front() ;

        if (temp1->right!=NULL)
        {
            g.push(temp1->right) ;
        }


        if (temp1->left!=NULL)
        {
            g.push(temp1->left) ;
        }
        
      

        gdata.push_back(temp1->data);
        g.pop() ;
        
    }
    std::reverse(gdata.begin(),gdata.end()) ;
    for (int i1 = 0; i1 < gdata.size(); i1++)
    {
        cout<<" "<<gdata[i1] ;
    }
    



    return 0;
}






