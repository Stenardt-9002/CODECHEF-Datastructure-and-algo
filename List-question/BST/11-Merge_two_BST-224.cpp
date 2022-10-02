// https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/
// https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val ; left=right=NULL;
    }
};



void inroder_vec(Node *root , vector<int> &getorder)
{
    if (root==NULL)
        return ;    

    inroder_vec(root->left, getorder);
    getorder.push_back(root->data) ;
    inroder_vec(root->right, getorder);
}


vector<int> merge_vec(vector<int> inordertree1,vector<int> inordertree2)
{
    int n = inordertree1.size() ;
    int m = inordertree2.size() ;
    int i =0,j=0,k=0 ;
    vector<int> asn1(n+m) ;

    while (i<n && j<m)
    {
        if (inordertree1[i]<inordertree2[j])
        {
            // asn1.push_back(inordertree1[i]) ; i++ ;
            asn1[k] = inordertree1[i] ; i++ ;
        }
        else
        {
            asn1[k]  = inordertree2[j] ; j++ ;
        }
        k++ ;
    }

    while (i<n)
    {
        asn1[k++] = inordertree1[i++];
    }
    while (j<m)
    {
        asn1[k++] = inordertree2[j++];
    }
    return asn1 ;
}


Node *create_BST_from_vec(vector<int> vec1,int srart,int end)
{
    if (srart>end)
        return NULL;    

    int mid1 = (srart+end)/2;

    Node *root = new Node(vec1[mid1]);
    root->left = create_BST_from_vec(vec1,srart,mid1-1) ;
    root->right = create_BST_from_vec(vec1,mid1+1,end) ;
    return root ;
}



Node *merge_two_balanced(Node *tree1 , Node *tree2)
{
    if (tree1==NULL&&tree2==NULL)
    return NULL ;

    if(tree1 == NULL)
        return tree2 ;

    if(tree2==NULL)
        return tree2 ;
    
    vector<int> inordertree1 ,inordertree2 ;

    inroder_vec(tree1,inordertree1) ;
    inroder_vec(tree2,inordertree2) ;

    //merge the 
    vector<int> asbn1 = merge_vec(inordertree1,inordertree2);
    int start1 = 0;int end = asbn1.size();
    Node *ans1 = create_BST_from_vec(asbn1,start1,end-1) ;
    return ans1;

}
