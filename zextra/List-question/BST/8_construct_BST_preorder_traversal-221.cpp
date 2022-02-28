
// https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversal-set-2/?ref=lbp
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val ;
        left = right = NULL;
    }
} ;
 


Node *constructtree(vector<int> preordertra , int n)
{
    stack<Node *> s1 ; 
    Node * root = new Node(preordertra[0]);
    s1.push(root);
    int i ; 
    Node *temp ;

    for ( i = 1; i < n; i++)
    {
        temp = NULL ;
        while (!s1.empty() && preordertra[i]>(s1.top())->data )
        {
            temp = s1.top() ; s1.pop() ;
        }
        if (temp!=NULL)
        {
            // means right child of last stack value that was smallest
            temp->right = new Node(preordertra[i]) ;
            s1.push(temp->right);
        }
        else
        {
            //means left child of last stack value 
            temp = s1.top() ;
            temp->left = new Node(preordertra[i]) ;
            s1.push(temp->left) ;
        }
    }
        return root ;
    


}



int main(int argc, char const *argv[])
{
    int n ; 
    cin>>n ;

    vector<int> preval ;
    int temp1 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>temp1; preval.push_back(temp1);
    }
    
    

    return 0;
}




