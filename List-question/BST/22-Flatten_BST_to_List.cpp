
// https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void inorder_util(Node *cunt , Node* &prev)
{
    if(cunt==NULL)
        return ;
    inorder_util(cunt->left , prev);
    prev->left = NULL ;
    prev->right = cunt ;
    prev = cunt ;
    inorder_util(cunt->right , prev);
}


Node *flaten_toSorted_List(Node* parent )
{
    Node *dummy = new Node(-1);
    Node *prev = dummy ;
    inorder_util(parent, prev);
    prev->right=prev->left = NULL ;

    return dummy->right ;

}



