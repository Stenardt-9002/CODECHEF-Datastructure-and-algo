// https://practice.geeksforgeeks.org/problems/complete-binary-tree/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout

// #define MOD1 1000000007
struct Node
{
    int data ;
    struct Node *left ,*right ;
    Node(int val)
    {
        data = val ;
        left = right = NULL ;
    }

};


bool isCompleteBT(struct Node* root)
{
    //code here
    if(root==NULL)
        return false ;
    queue<Node*> q1 ;
    q1.push(root);
    bool visitedNULL = false ;
    while (!q1.empty())
    {
        Node *curr = q1.front();
        q1.pop();
        if(curr==NULL)
            visitedNULL = true ;
        else 
        {
            if(visitedNULL)
                return false ;
            
            q1.push(curr->left);
            q1.push(curr->right);
        }

    }
    return true ;
} 

int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tesecase ; cin>>tesecase ;
    while(tesecase--)
    {   
        int n,m,k ;
        cin>>m>>n>>k ;
        cout<<endl<<knots(m,n,k);
    }
    return 0;
}

