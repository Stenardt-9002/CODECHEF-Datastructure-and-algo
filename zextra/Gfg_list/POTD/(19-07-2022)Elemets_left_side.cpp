// https://practice.geeksforgeeks.org/problems/count-smaller-elements2214/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


struct TreeNode
{
    int data , size, height ;
    struct TreeNode *left ;struct TreeNode *right ;

};
struct TreeNode* newTreeNode(int key)
{
    struct TreeNode* intup = NULL ;
        intup->data = key ;
        intup->left = NULL ;
        intup->right = NULL ;
        intup->height = 1;
        intup->size = 1;
    return intup ;
};

int height_util(struct TreeNode *i)
{
    if(i==NULL)
        return 0; 
    return i->height; 
}


int size_util(struct TreeNode *i)
{
    if(i==NULL)
        return 0; 
    return i->size; 
}


int get_height_diff(struct TreeNode *i)
{
    if(i==NULL)
        return 0 ;

    return height_util(i->left)-height_util(i->right);
}




struct TreeNode* rightRotate_fuc(struct TreeNode *nodeinput)
{
    if(nodeinput==NULL)
        return NULL ;
    TreeNode *letx = nodeinput->left ;
    TreeNode *oldright = letx->right ;

    letx->right = nodeinput ; 
    nodeinput->left = oldright ;
    //update height 
    nodeinput->height = max( height_util(nodeinput->left) , height_util( nodeinput->right))+1 ;
    letx->height = max( height_util(letx->left) , height_util( letx->right))+1 ;
    
    //update size
    nodeinput->size =  size_util(nodeinput->left) + size_util( nodeinput->right)+1 ;
    letx->size =  size_util(letx->left) + size_util( letx->right)+1 ;
    
    return letx ;
}




struct TreeNode* leftRotate_fuc(struct TreeNode *nodeinput)
{
    if(nodeinput==NULL)
        return NULL ;
    TreeNode *lety = nodeinput->right ;
    TreeNode *oldleft = lety->left ;

    lety->left = nodeinput ; 
    nodeinput->right = oldleft ;
    //update height 
    nodeinput->height = max( height_util(nodeinput->left) , height_util( nodeinput->right))+1 ;
    lety->height = max( height_util(lety->left) , height_util( lety->right))+1 ;
    
    //update size
    nodeinput->size =  size_util(nodeinput->left) + size_util( nodeinput->right)+1 ;
    lety->size =  size_util(lety->left) + size_util( lety->right)+1 ;
    
    return lety ;
}

struct TreeNode* insert_in_tree(struct TreeNode* curnode , int data_Val ,int *count)
{
    if(curnode==NULL)
        return newTreeNode(data_Val);

    
    if(data_Val<=curnode->data)
        curnode->left = insert_in_tree(curnode->left , data_Val , count);

    else 
    {
        curnode->right = insert_in_tree(curnode->right , data_Val , count);
        // if on right add the left side elements one that are smaller than it 
        *count =*count+ size_util(curnode->left)+1;
    }

    curnode->height = max(height_util(curnode->left),height_util(curnode->right))+1 ;
    curnode->size = size_util(curnode->left) + size_util(curnode->right)+1 ;


    int balance_factor = get_height_diff(curnode);
    //left left 
    if(balance_factor>1 && data_Val<curnode->left->data)
        return rightRotate_fuc(curnode);

    //right right
    if(balance_factor<-1 && data_Val>curnode->right->data)
        return leftRotate_fuc(curnode);


    //left right
    if(balance_factor>1 && data_Val>curnode->left->data)
    {
        curnode->left = leftRotate_fuc(curnode->left);
        return rightRotate_fuc(curnode);
    }

    //right left
    if(balance_factor<-1 && data_Val<curnode->right->data)
    {
        curnode->right = rightRotate_fuc(curnode->right);
        return leftRotate_fuc(curnode);
    }


    return curnode ;

}


void util_create_B_BST(vector<int> &answer1, int arr[], int n)
{
    TreeNode* root = NULL ; 
    int data_ptr = 0 ;
    int *ans21  = new int[n] ;
    for (int i1 = 0; i1 < n; i1++)
        ans21[i1] = 0 ;

    for (int i1 = n-1; i1 >=0; i1--)
        root = insert_in_tree(root , arr[i1] , &ans21[i1])    ;

    delete []ans21 ;
}


vector<int> constructLowerArray(int *arr, int n) 
{
    // code here

    vector<int> asn1(n,0) ;
    util_create_B_BST(asn1,arr, n);
    return asn1 ;
}


void countSmallerRight(int A[], int len)
{
    multiset<int> s;
    vector<int> countSmaller(len,0);
    for (int i = len - 1; i >= 0; i--) {
        s.insert(A[i]);
        auto it = s.lower_bound(A[i]);
        countSmaller[i] = distance(s.begin(), it);
    }
    
    for (int i = 0; i < len; i++)
        cout << countSmaller[i] << " ";
}

int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 

    int testcase ;
    int n;
    // testcase=2 ;
    cin>>testcase;
    while (testcase--)
    {
        cin>>n;
        int *array = new int[n];
        for (int i1 = 0; i1 < n; i1++)
            cin>>array[i1];
        vector<int> ans1 = constructLowerArray(array , n);
        for(auto x : ans1)
            cout<<" "<<x ;
        cout<<endl ;
    }
    return 0 ;
}






