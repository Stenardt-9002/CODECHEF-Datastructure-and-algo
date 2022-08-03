

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* post_order_util(int pre[], int start , int end)
{
    if(start-end<0)
        return NULL ;
    if(start-end==0)
        return newNode(pre[start]) ;
    
    Node *curr = newNode(pre[start]);
    int i1 ;
    for ( i1 = start+1; i1 <=end; i1++)
        if(pre[start]<pre[i1])  
            break ;
    cout<<"endl"<<i1<<endl;
    curr->left = post_order_util(pre ,start+1 , i1 );
    curr->right= post_order_util(pre ,i1+1 , end );

    return curr ;
}


Node* post_order(int pre[], int size)
{
    //code here
    
    // cout<<"BRUH\n";
    if(size==0) 
        return NULL ;

    
    stack<Node*> s1  ;
    Node *root = newNode(pre[0]);
    s1.push(root);
    for (int i1 = 1; i1 < size; i1++)
    {
        Node *curnode = newNode(pre[i1]);
        if(pre[i1]<s1.top()->data)
            s1.top()->left = curnode ;
        else 
        {
            Node *parent = s1.top();
            while (!s1.empty()&&pre[i1]>s1.top()->data)
            {
                parent = s1.top();
                s1.pop();
            }
            parent->right = curnode ;
        }
        s1.push(curnode);
    }
    


    // int start = 0 ;
    // int end = size-1;
    // Node* ans1 = post_order_util(pre,start , end );
    // cout<<ans1->data<<endl ;

    return root ;
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
    testcase=1 ;
    while (testcase--)
    {
        cin>>n;
        int *arr1 = new int[n];
        for (  int i1 = 0; i1 < n; i1++)
            cin>>arr1[i1];

        Node* anms1 = post_order(arr1,n);
        cout<<anms1->data ;

    }
    return 0 ;
}