

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;

typedef  long long ll1d;

const int mod1 = (1e9+7);


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};



vector <int> preorder(Node* root)
{
  // Your code here
    vector<int> ans1 ;

    Node *cur=NULL,*pre = NULL ;
    cur = root ;
    while (cur!=NULL)
    {
        if(cur->left==NULL)
        {
            ans1.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            pre = cur->left ;
            while (pre->right!=NULL && pre->right!=cur)
                pre = pre->right ;

            if(pre->right==cur)
            {
                pre->right = NULL ;
                cur = cur->right;
            }
            else
            {
                pre->right = cur ;
                ans1.push_back(cur->data);
                cur = cur->left ;
            }
        }
    }
    return ans1;
}