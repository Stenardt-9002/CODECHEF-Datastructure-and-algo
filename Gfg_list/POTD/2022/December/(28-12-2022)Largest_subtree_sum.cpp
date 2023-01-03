
// https://practice.geeksforgeeks.org/problems/largest-subtree-sum-in-a-tree/1






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



class Solution {
  public:
    int recruvsie(Node* root , int &ans)
    {
        if(root==NULL)
            return 0 ;
            
        int l = this->recruvsie(root->left , ans);
        int r = this->recruvsie(root->right , ans);
        ans = max(ans , l+r + root->data);
        
        return l+r + root->data ;
    }
    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root)
    {
        //Write your code here
        int ans = 0;
        this->recruvsie(root,ans) ;
        return ans ;
        
    }
};
