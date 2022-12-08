// https://practice.geeksforgeeks.org/problems/shortest-path-by-removing-k-walls/1












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



int recursive_data(Node *n1 , int &curr , int K)
{
    if(n1==NULL)
        return -1;
    int l1 = recursive_data(n1->left , curr , K);
    if(++curr == K)
        return n1->data ;
    int r1 = recursive_data(n1->right , curr , K);
    if(l1>0)
        return l1 ;
    if(r1>0)
        return r1 ;
    return -1;
    
}




class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) 
    {
        // add code here.
        int curr = 0 ;
        int data = recursive_data(root , curr , K);
        return data ;
    }
};