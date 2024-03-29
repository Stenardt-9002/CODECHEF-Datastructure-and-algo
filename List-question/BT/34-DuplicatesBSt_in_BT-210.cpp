

// https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1




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



string ionrderUtil(Node *root , unordered_map<string,int> &hash_map,vector<Node *> &ans1)
{
    if(root==NULL)
        return "";

    string str1 = "(";
    str1+=ionrderUtil(root->left,hash_map,ans1);
    str1+=to_string(root->data);
    str1+=ionrderUtil(root->right,hash_map,ans1);
    str1+=")";

    if(hash_map.find(str1)==hash_map.end())//not found
        hash_map[str1]=1 ;
    else
    {
        hash_map[str1]+=1 ;
        if(hash_map[str1]==2 )//duplicate found 
            ans1.push_back(root);
    }
    return str1 ;
}




vector<Node*> printAllDups(Node* root)
{
    // Code here
    unordered_map<string,int> hash_map ;
    vector<Node *> ans1 ; 
    ionrderUtil(root, hash_map ,ans1);
    return ans1 ;
}





