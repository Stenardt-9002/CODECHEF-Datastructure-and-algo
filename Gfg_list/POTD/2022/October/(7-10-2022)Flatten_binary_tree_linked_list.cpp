// https://practice.geeksforgeeks.org/problems/mila-and-strings0435/1



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;


struct Node{
    int key ;
    Node *left ,*right ;
};

Node* newNode(int key)
{
    Node* node = new Node ;
    node->key = key ;
    node->left = node->right = NULL ;
    return (node);
}

void flatten(Node *root)
{
    //code here
    Node* traverse = root ;
    while(traverse!=NULL )
    {
        if(traverse->left!=NULL)
        {
            Node *ptr_left_child = traverse->left ;
            Node *save_righ_child = traverse->right ;
            traverse->right = ptr_left_child ;
            traverse->left = NULL ;
            while (ptr_left_child->right!=NULL)
                ptr_left_child = ptr_left_child->right;

            ptr_left_child->right  = save_righ_child ;
        }    
        traverse = traverse->right ;
    }

}










