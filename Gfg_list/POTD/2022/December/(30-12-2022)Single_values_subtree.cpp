// https://practice.geeksforgeeks.org/problems/single-valued-subtree/1
    










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
    int data ;
    struct Node *left , *right ;
};






class Solution
{
    public:
    bool dfs_util(Node *cur , int &ans1)
    {
        if(cur==NULL)
            return true ;
        bool l = dfs_util(cur->left , ans1);
        bool r = dfs_util(cur->right ,ans1);
        bool ok = true ;
        if(cur->left!=NULL)
        {
            if(cur->data!=cur->left->data)
                ok = false ;
        }
        if(cur->right!=NULL)
        {
            if(cur->data!=cur->right->data)
                ok = false ;
        }
        if(ok&&l&&r)
            ans1++ ;
        return ok&&l&&r;
        
    }
    int singlevalued(Node *root)
    {
        //code here
        int ans1 = 0 ;
        dfs_util(root, ans1);
        return ans1 ;
    }
    
};