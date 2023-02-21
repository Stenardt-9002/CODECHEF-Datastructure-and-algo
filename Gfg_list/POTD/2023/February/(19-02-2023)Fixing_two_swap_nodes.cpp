



// https://practice.geeksforgeeks.org/problems/6c4053871794c5e7a0817d7eaf88d71c4bb4c2bc/1














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










struct Node
{
    int data;
    struct Node *left, *right;
};






void recrusrive(Node* node , vector<int> &correct_o ,int &cur_index)
{
    if(node==NULL)
        return ; 
    recrusrive(node->left , correct_o , cur_index);
    node->data = correct_o[cur_index++];
    recrusrive(node->right , correct_o , cur_index);

}


class Solution {
  public:
    struct Node *correctBST(struct Node *root) 
    {    
        // code here
        struct Node* current , *pre ;
        if(root==NULL)
            return NULL;

        vector<int> correct_ ;
        current = root ;
        while (current!=NULL)
        {
            if(current->left==NULL)
            {
                correct_.push_back(current->data);
                current = current->right ;
            }
            else 
            {
                pre = current->left ;
                while (pre->right!=NULL && pre->right!=current)
                    pre = pre->right ;

                if(pre->right!=NULL)
                {
                    pre->right = NULL;
                    correct_.push_back(current->data);
                    current = current->right ;
                }
                else 
                {
                    pre->right = current ;
                    current = current->left ;
                }


            }

        }
        
        sort(correct_.begin() , correct_.end());
        int index = 0 ;
        recrusrive(root , correct_ , index);

        return root ;
        
        
    }
};

