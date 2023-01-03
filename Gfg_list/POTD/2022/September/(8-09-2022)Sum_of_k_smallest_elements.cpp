// https://practice.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1










#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

int sum(Node* root, int k) 
{ 
  
    // Your code here
    stack<Node*> s1 ;
    Node *curr = root ;
    int i1 = 0 ;
    int sum1 = 0 ;
    while((curr!=NULL || !s1.empty()) && i1<k )
    {
        while (curr!=NULL)
        {
            s1.push(curr);
            curr = curr->left ;
        }
        curr = s1.top();
        s1.pop();

        sum1+=curr->data ;
        i1+=1 ;

        curr = curr->right;
    }
    return sum1 ;

} 

