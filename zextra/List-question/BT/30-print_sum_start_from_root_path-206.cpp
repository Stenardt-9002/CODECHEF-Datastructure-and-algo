// https://practice.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1/



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



void printKpath_util(Node *root, int sum,vector<int>&temp1,vector<vector<int>>&temp_final,int &cur_sum)
{
    if(root==NULL)
        return ;

    // vector<int> temp2 ;
    temp1.push_back(root->data);
    int cur_ss = cur_sum+root->data ;
    printKpath_util(root->left,sum,temp1,temp_final,cur_ss);
    printKpath_util(root->right,sum,temp1,temp_final,cur_ss);


    if(cur_ss==sum)
        temp_final.push_back(temp1);

    // int sum1=0;
    // for (int i1 = temp1.size()-1; i1 >=0; i1--)
    // {
    //     temp2.push_back(temp1[i1]);
    //     sum1+=temp1[i1] ;
    //     if(sum1==sum)
    //         temp_final.push_back(temp2);
    // }
    
    temp1.pop_back();
}


    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<vector<int>> ans1 ;
        vector<int> path ;
        int sum1 = 0;
        printKpath_util(root,sum,path,ans1,sum1);
        return ans1 ;
    }



int main(int argc, char const *argv[])
{
    
    return 0;
}





