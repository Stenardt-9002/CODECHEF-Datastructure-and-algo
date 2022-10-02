
// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1/




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
    Node(int val)
    {
        data = val ;
        left = right = NULL ;
    }
};
void serialize1(Node *root,vector<int> &ans1)
{
    if (root == NULL)
    {
        ans1.push_back(-1);
        return;
    }
    ans1.push_back(root->data);
    serialize1(root->left, ans1);
    serialize1(root->right, ans1);
}

void deserilaise_util(Node* &ans1 , vector<int>A , int &index)
{
    if(index>=A.size() ||A[index]==-1)
        return ;

    ans1 = new Node(A[index]);
    deserilaise_util(ans1->left , A , ++index);
    deserilaise_util(ans1->right , A , ++index);
}
    // vector<int> serialize(Node *root) 
    // {
    //     //Your code here
    //         if(root==NULL)
    //         return {};
        
    //     vector<int>ans2;
    //     serialize1(root,ans2);
    //     return ans2 ;
    // }
    
    // //Function to deserialize a list and construct the tree.
    // Node * deSerialize(vector<int> &A)
    // {
    //    //Your code here
    //        Node * ans1 =NULL ; 
    //         int i1 = 0;
    //         deserilaise_util(ans1,A,i1);
    //         return ans1 ;
    // }


vector<int> serialize(Node *root) 
{
    //Not working 


    // if(root==NULL)
    //     return {};
    // //iterative preorder traversal with markers 
    // stack<Node*> s1 ;
    // Node *curptr = root ;
    // Node *markert = new Node(-1);
    // vector<int> preodrer_with_marker ;
    // bool visted_NULL_node ;
    // while (!s1.empty() || curptr!=NULL )
    // {
    //     visted_NULL_node= false  ;

    //     while (curptr!=NULL)
    //     {
    //         visted_NULL_node= false  ;
    //         preodrer_with_marker.push_back(curptr->data);
    //         if (curptr->right!=NULL)
    //             s1.push(curptr->right);
    //         else if(curptr->data!=-1)//NOT null
    //             {
    //                 s1.push(markert);
    //                 visted_NULL_node = true ;
    //             }
    //         curptr = curptr->left ;

    //     }
    //     if(visted_NULL_node)
    //         preodrer_with_marker.push_back(-1);//pushing marker
    //     if(!s1.empty())
    //     {
    //         curptr = s1.top();
    //         s1.pop();
    //     }
    // }
    // return preodrer_with_marker;


    if(root==NULL)
        return {};
    vector<int>ans1 ;
    queue<Node*> q1 ;
    q1.push(root);
    while (!q1.empty())
    {
        Node* curNode = q1.front();
        q1.pop() ;
        if(curNode==NULL) 
            ans1.push_back(-1);//marker
        else 
            ans1.push_back(curNode->data);
        if(curNode!=NULL)
        {
            q1.push(curNode->left) ;
            q1.push(curNode->right) ;
        }
    }
    return ans1 ;

}

Node* deSerialize(vector<int> &A)
{
    if(A.size()==0)
        return NULL ;

    int n = A.size();
    Node *root = new Node(A[0]) ;
    queue<Node*> q1 ;
    q1.push(root);
    Node* temp1 ;
    int i1 = 1 ;
    while (!q1.empty())
    {
        temp1 = q1.front() ;
        q1.pop();
        i1++ ;
        if(i1<n)
        {       
            if (A[i1]==-1)
                temp1->left = NULL ;
            else
            {
                temp1->left = new Node(A[i1]) ;
                q1.push(temp1->left);
            } 
        }           


        i1++ ;
        if(i1<n)
        {
            if (A[i1]==-1)
                temp1->right = NULL ;
            else
            {
                temp1->right = new Node(A[i1]) ;
                q1.push(temp1->right);
            }  
        }
    }
    return root ;
}


void inorder_n(Node* node1)
{
    if(node1!=NULL)
    {
        inorder_n(node1->left);
        cout<<" "<<node1->data ;
        inorder_n(node1->right);
    }
}

void preorder_n(Node* node1)
{
    if(node1!=NULL)
    {
        cout<<" "<<node1->data ;
        preorder_n(node1->left);
        preorder_n(node1->right);
    }
}



int main(int argc, char const *argv[])
{

        Node *root = new Node(9);
    root->left = new Node(5);
    root->right = new Node(14);
    root->left->left= new Node(3);
    root->left->right= new Node(8);
    // root->left->left->left= new Node(1);

    
    root->right->left = new Node(12);
    root->right->right = new Node(16);
    root->right->right->right = new Node(24);
    vector<int>ans1 = serialize(root);
    cout<<"\nPreorder ";preorder_n(root);
    cout<<"\nInorder ";inorder_n(root);

    cout<<endl;
    // for (auto x:ans1)
    //     cout<<" "<<x;
 
    root = deSerialize(ans1);
    cout<<"\nPreorder ";preorder_n(root);
    cout<<"\nInorder ";inorder_n(root);

    return 0;
}






