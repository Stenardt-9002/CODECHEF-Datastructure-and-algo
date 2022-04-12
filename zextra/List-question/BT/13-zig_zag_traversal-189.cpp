    
    
//   https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1  



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int key)
    {data = key;}
};





vector <int> zigZagTraversal(Node* root)
{
    // Code here

    queue<Node*> q1 ;
    vector<int> ans1 ;
    q1.push(root) ;
    int cur_que_size;
    bool flip = false;
    vector<int> one_levl;
    while (!q1.empty())
    {
        cur_que_size = q1.size();
        one_levl.clear();
        for (int i1 = 0; i1 < cur_que_size; i1++)
        {
            Node *temp1 = q1.front();
            one_levl.push_back(temp1->data);
            q1.pop();
            if(temp1->left!=NULL)
                q1.push(temp1->left);

            if(temp1->right!=NULL)
                q1.push(temp1->right);
                
        }
        if(flip)
            reverse(one_levl.begin(),one_levl.end());
        for (auto x : one_levl)
            ans1.push_back(x);
        flip = !flip ;
    }
    return ans1 ;
}


int main(int argc, char const *argv[])
{
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(-6);
    // root->right->right = new Node(2);

    //   Node* root = new Node(7);
    // root->left = new Node(9);
    // root->right = new Node(7);
    // root->left->left = new Node(8);
    // root->left->right = new Node(8);
    // root->right->left = new Node(6);
    // root->left->left->left = new Node(10);
    // root->left->left->right = new Node(9);



    Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(1);

    vector<int> a1 = zigZagTraversal(root);
    cout<<endl;
    for (auto x : a1)
        cout<<" "<<x;
    
    return 0;
}
