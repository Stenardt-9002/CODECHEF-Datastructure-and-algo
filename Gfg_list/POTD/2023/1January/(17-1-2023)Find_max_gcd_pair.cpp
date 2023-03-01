
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

const int mod1 = (1e9+7);
const long long int mod2 =  1e18 ;

#define mii map<int,int> 
#define msi map<string,int> 
#define musi unordered_map<string,int> 

typedef  long long int lld;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);







struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution
{
public:

    void dfs_util(Node* root,int &ans ,int &gcd_val_max)
    {
        if(root==NULL)
            return ;
        
        if(root->left!=NULL && root->right!=NULL)
        {
            int gcd_val = __gcd(root->left->data,root->right->data);
            if(gcd_val>gcd_val_max)
            {
                gcd_val_max = gcd_val ;
                ans = root->data ;
            }
            else if(gcd_val==gcd_val_max && root->data>ans)
                ans = root->data ;
        }
        if(root->left!=NULL)
            dfs_util(root->left , ans , gcd_val_max);
        if(root->right!=NULL)
            dfs_util(root->right , ans , gcd_val_max);
        
        return ;
        
    }


    int maxGCD( Node* root)
    {
        //code here
        int ans = 0 ;
        int gcd_val_max = 1;
        if(root==NULL)
            return 0 ;
        dfs_util(root, ans , gcd_val_max);
        return ans ;
    }
};

