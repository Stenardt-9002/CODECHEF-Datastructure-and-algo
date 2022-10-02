
// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1


// IMP VISIT https://leetcode.com/problems/find-duplicate-subtrees/

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
    Node(int val)
    {
        data = val ;
        left = right = NULL ;
    }
};


    string dpuTree_Util(Node *root, unordered_set<string> &hash_map,bool &anss)
    {
        string s1 = "";
        if(root==NULL)
            return "#";
    
        string leftsubtree = dpuTree_Util(root->left,hash_map,anss);
        if(leftsubtree.compare(s1)==0)
            return s1 ;
        
    
        string rightsubtree = dpuTree_Util(root->right,hash_map,anss);
        if(rightsubtree.compare(s1)==0)
            return s1 ;
        
        s1 = s1+to_string(root->data)+leftsubtree+rightsubtree;
        int length = to_string(root->data).size() ;
    
        if (s1.length()>2+length && hash_map.find(s1)!=hash_map.end())
            return "";
    
        hash_map.insert(s1);
        return s1 ;
    }
        
    
    int dupSub(Node *root) 
    {
         // code here
             unordered_set<string> hash_map;
            bool ans1 = false ;
            string final = dpuTree_Util(root,hash_map,ans1);
            
            if(final.compare("")==0)
                return 1 ;
            return 0 ;
    }
void inorder_n(Node* node1)
{
    if(node1!=NULL)
    {
        inorder_n(node1->left);
        cout<<" "<<node1->data ;
        inorder_n(node1->right);
    }
}

void preorder_n(Node* node1)
{
    if(node1!=NULL)
    {
        cout<<" "<<node1->data ;
        preorder_n(node1->left);
        preorder_n(node1->right);
    }
}



int main(int argc, char const *argv[])
{

        Node *root = new Node(9);
    root->left = new Node(5);
    root->right = new Node(14);
    root->left->left= new Node(3);
    root->left->right= new Node(8);
    // root->left->left->left= new Node(1);

    
    root->right->left = new Node(12);
    root->right->right = new Node(16);
    root->right->right->right = new Node(24);
    // vector<int>ans1 = serialize(root);
    // cout<<"\nPreorder ";preorder_n(root);
    // cout<<"\nInorder ";inorder_n(root);

    // cout<<endl;
    // // for (auto x:ans1)
    // //     cout<<" "<<x;
 
    // root = deSerialize(ans1);
    // cout<<"\nPreorder ";preorder_n(root);
    // cout<<"\nInorder ";inorder_n(root);

    return 0;
}



