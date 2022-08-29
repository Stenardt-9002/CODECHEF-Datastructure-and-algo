// https://practice.geeksforgeeks.org/problems/next-right-node/1



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
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};



Node *nextRight(Node *root, int key)
{
    //code here
        queue<Node*> q1 ;
        queue<Node*> q2 ;
    
        q1.push(root);
    
    
        while(!q1.empty())
        {
            int ize = q1.size(); 
            for (int i1 = 0; i1 < ize; i1++)
            {
                Node* temp1 = q1.front();
                int data1 = temp1->data ;
                q1.pop();
                if(data1 == key)
                {
                    if(q1.empty())
                        return new Node(-1) ;
                    return q1.front();
                }
                if(temp1->left!=NULL)
                    q2.push(temp1->left);
                if(temp1->right!=NULL)
                    q2.push(temp1->right);
            }
            while(!q2.empty())
                q1.push(q2.front()) , q2.pop();
        }
    
        return new Node(-1) ;


}




