// https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1/



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

    
    static int find_max_util(Node *root, int &ans1)
    {
        if(root==NULL)
            return 0 ;
        
        int left_sum = max(0,find_max_util(root->left ,ans1));
        int rigt_sum = max(0,find_max_util(root->right ,ans1));
        ans1 = max(ans1 , root->data+left_sum+rigt_sum) ;
        return root->data + max(left_sum,rigt_sum);
    }
    
    
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int ans1 = INT_MIN ;
        int cpat = find_max_util(root, ans1);
        return max(cpat, ans1);
    }

