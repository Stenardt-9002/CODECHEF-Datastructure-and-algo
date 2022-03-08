// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1





#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void inorder1(Node *roo1, vector<int> &ar1)
{
    if (roo1!=NULL)
    {
        inorder1(roo1->left,ar1) ;
        ar1.push_back(roo1->data) ;
        inorder1(roo1->right,ar1);

    }
    return ;
    
}

vector<int> mer1ge(vector<int> ar1,vector<int> ar2)
{
    int siz1 = ar1.size() ;
    int siz2 = ar2.size() ;

    vector<int>ar3(siz1+siz2) ;

    int i1 = 0,j1 =0;
    int k1 = 0;
    while (i1<siz1 && j1<siz2 )
    {
        if (ar1[i1]<ar1[j1])
            ar3[k1++] = ar1[i1++];

        else
            ar3[k1++] = ar2[j1++];
    }

    while (i1<siz1)
        ar3[k1++] = ar1[i1++];
    
    while (j1<siz2)
        ar3[k1++] = ar2[j1++];

    return ar3;

}




int countPairs(Node* root1, Node* root2, int x)
{
    vector<int> ar1 ,ar2;
    inorder1(root1,ar1);
    inorder1(root2,ar2) ;
    vector<int> ar3 = mer1ge(ar1,ar2);

    int i1 = 0,j1=ar3.size()-1;

    int asn1 = 0;
    while (i1<=j1)
    {
        if (x>ar3[i1]+ar3[j1])
            i1++ ;
        else if(x<ar3[i1]+ar3[j1])
            j1-- ;
        else
            {
                asn1++ ;
                if (i1+1<j1 && ar3[i1+1]==ar3[i1])
                    i1++;

                else if (i1<j1-1 && ar3[j1-1]==ar3[j1])
                    j1-- ;

                else 
                    i1++ ;
            }

    }
    
    return asn1 ;
}




