
// https://practice.geeksforgeeks.org/problems/complete-binary-tree/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int val)
    {
        data = val ;
        left= right=NULL ;
    }
};

Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
bool isCompleteBT(Node* root)
{
    //code here
    queue<Node*> q1 ;
    q1.push(root);

    bool wehaveNULLnow = false ;

    while (!q1.empty())
    {
        Node* curr = q1.front();
        q1.pop();

        if(curr==NULL)
        {
            wehaveNULLnow=true ;
        }
        else 
        {
            if(wehaveNULLnow)
                return false ;

            q1.push(curr->left);
            q1.push(curr->right);
        }
    }
    



}

