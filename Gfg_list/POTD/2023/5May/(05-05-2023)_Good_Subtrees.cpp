

// https://practice.geeksforgeeks.org/problems/df12afc57250e7f6fc101aa9c272343184fe9859/1







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


unordered_set<int> recursive_util(Node *root ,int k , int &ans)
{
    if(root==NULL)
        return {};
    if(root->left==NULL && root->right == NULL)
    {
        if(k>0)
            ans++ ;
        unordered_set<int>s1 ;
        s1.insert(root->data);
        return s1 ; 
    }
    unordered_set<int>s1 = recursive_util(root->left ,k, ans);
    unordered_set<int>s2 = recursive_util(root->right ,k, ans);
    s1.insert(s2.begin(),s2.end());
    s1.insert(root->data);
    if(s1.size()<=k)
        ans++ ;
    return s1 ;
}
class Solution{
public:
    int goodSubtrees(Node *root,int k){
        // Code here
        int ans = 0 ; 
        recursive_util(root,k,ans);
        return ans ; 
    }
};