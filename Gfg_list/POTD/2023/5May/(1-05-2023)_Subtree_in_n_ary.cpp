// https://practice.geeksforgeeks.org/problems/079dee7e7db7a784ed73f604e3cf1712432edf79/1










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


class Node
{
    
public:
    int data ; vector<Node*>children ;
    Node(int val)
    {
        this->data = val ; 
    }
};





class Solution{
public:
    string inorder_t(Node *root , map<string,int>&hash_inorder )
    {
        if(root==NULL)
            return "";
        string ans ="_"+to_string(root->data)+"_";
        
        for(auto c: root->children)
            ans+=inorder_t(c,hash_inorder);
        hash_inorder[ans]++;
        return ans ; 
        
    }
    int duplicateSubtreeNaryTree(Node *root)
    {
        // Code here
        map<string,int> hash_inorder ; 
        inorder_t(root,hash_inorder);
        int ans = 0 ;
        for(auto c : hash_inorder)
            ans+=(c.second>1);
        return ans ; 
    }
};










