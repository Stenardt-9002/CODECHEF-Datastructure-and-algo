
















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
     Node* left, *right;
}; 

class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) 
    {
        // Your code here
        if(root==NULL)
            return 0 ;
        queue<Node*>q1 ;
        q1.push(root);
        int sum_val = INT_MIN ;
        while(!q1.empty())
        {
            int size = q1.size();
            int sumval = 0 ;
            while(size--)
            {
                Node *temp = q1.front();
                q1.pop();
                sumval+=temp->data;
                if(temp->left)
                    q1.push(temp->left);
                if(temp->right)
                    q1.push(temp->right);
            }
            sum_val = max(sum_val , sumval);
        }
        return sum_val;
    }
};