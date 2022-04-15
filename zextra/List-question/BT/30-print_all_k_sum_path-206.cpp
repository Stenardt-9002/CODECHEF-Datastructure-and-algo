


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

void printKPathUtil(Node *root , vector<int> &curentpath , int sum_val  , vector<vector<int>> &all_path)
{
    if(root==NULL)
        return ; 

    vector<int> cure_path_sum ;
    curentpath.push_back(root->data);
    printKPathUtil(root->left,curentpath , sum_val , all_path);
    printKPathUtil(root->right,curentpath , sum_val , all_path);

    int sum_1 = 0;
    for (int j1 = curentpath.size()-1; j1 >=0; j1--)
    {
        sum_1+=curentpath[j1];
        cure_path_sum.push_back(curentpath[j1]);
        if(sum_1 == sum_val)
            all_path.push_back(cure_path_sum);
    }
    curentpath.pop_back();
}
int main(int argc, char const *argv[])
{
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(-6);
    // root->right->right = new Node(2);
    // cout<<findDist(root,2,3)<<endl;;



    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
    vector<int> curent_path ;
    vector<vector<int>> all_path1 ;

    printKPathUtil(root,curent_path,5,all_path1);
    for (auto x : all_path1)
        {
            cout<<endl;
            for (auto y : x)
                cout<<" "<<y ;
        }


    return 0;
}


