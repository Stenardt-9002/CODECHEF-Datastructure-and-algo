// https://practice.geeksforgeeks.org/problems/construct-tree-1/1/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;
  Node(int data)
  {
    this->data = data ;
    this->left = this->right = NULL ;
  }
};


Node* buildTree(int in[],int pre[], int n)
{
    // Code here
    set<Node*> set1 ;
    stack<Node*> sta_ck1 ;
    Node *root = NULL ;
    for (int i1 = 0,j1=0; i1 < n; )
    {
        Node* curnode = NULL ;

        do
        {
            curnode = new Node(pre[i1]);

            if (root==NULL)
                root = curnode ;
            if (sta_ck1.size()>0)
            {
                if (set1.find(sta_ck1.top())!=set1.end())
                {
                    set1.erase(sta_ck1.top()) ;
                    sta_ck1.top()->right = curnode ;
                    sta_ck1.pop() ;
                }
                else
                    sta_ck1.top()->left = curnode ;
            }
            sta_ck1.push(curnode)         ;

        } while (pre[i1++]!=in[j1]&&i1<n);
        
        curnode = NULL ;
        while (sta_ck1.size()>0 && j1<n && sta_ck1.top()->data==in[j1])
        {   
            curnode = sta_ck1.top() ;
            sta_ck1.pop() ;
            j1++ ;
        }
        
        if (curnode!=NULL)
        {
            set1.insert(curnode) ;
            sta_ck1.push(curnode) ;
        }

    }
    return root ;

}







