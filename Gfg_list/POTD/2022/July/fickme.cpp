// https://practice.geeksforgeeks.org/problems/count-smaller-elements2214/1

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


struct node
{
	int key;
	struct node *left;
	struct node *right;
	int height;
	int size;
};

int height(struct node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int size(struct node *N)
{
	if (N == NULL)
		return 0;
	return N->size;
}

struct node* newNode(int key)
{
	struct node* node = (struct node*)
						malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	node->size = 1;
	return(node);
}

struct node *rightRotate(struct node *y)
{
	struct node *x = y->left;
	struct node *T2 = x->right;

	x->right = y;
	y->left = T2;
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	y->size = size(y->left) + size(y->right) + 1;
	x->size = size(x->left) + size(x->right) + 1;
	return x;
}

struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *T2 = y->left;
	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	x->size = size(x->left) + size(x->right) + 1;
	y->size = size(y->left) + size(y->right) + 1;
	return y;
}

int getBalance(struct node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int key,
					int *count)
{
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key, count);
	else
	{
		node->right = insert(node->right, key, count);
		*count = *count + size(node->left) + 1;
	}


	node->height = max(height(node->left),
					height(node->right)) + 1;
	node->size = size(node->left) +
				size(node->right) + 1;

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

vector<int> constructLowerArray(int arr[], int n)
{
	int i, j;
	struct node *root = NULL;
	int *countSmaller = new int[n];

	for(i = 0; i < n; i++)
		countSmaller[i] = 0;
	
	for(i = n - 1; i >= 0; i--)
		root = insert(root, arr[i], &countSmaller[i]);
    
	vector<int> asn1(n,0);
    for(i = n - 1; i >= 0; i--)
		asn1[i] = countSmaller[i];
	
	return asn1;
    
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


