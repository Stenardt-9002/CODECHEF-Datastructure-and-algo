	
    

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include<bits/stdc++.h>
using namespace std;

// class Node{
	
// public:
// 	int val;
// 	int count;
// 	Node* left;
// 	Node* right;
	
// 	// Constructor
// 	Node(int num1, int num2)
// 	{
// 		this->val = num1;
// 		this->count = num2;
// 		this->left = this->right = NULL;
// 	}
// };

struct Node
{
	
public:
	int val;
	int count;
	Node* left;
	Node* right;
	
	Node(int num1, int num2)
	{
		this->val = num1;
		this->count = num2;
		this->left = this->right = NULL;
	}
};


int insert_node(Node*& curnode, int data1,	int value_less_than)
{
	
	if (curnode == NULL)
	{
		curnode = new Node(data1, 0);
		return value_less_than;
	}
	if (curnode->val < data1)
		return curnode->count + insert_node(curnode->right,data1,value_less_than + 1);
	else
	{
		curnode->count++;
		return insert_node(curnode->left, data1,value_less_than);
	}
}


vector<int> constructLowerArray(int *arr, int n) 
{
    vector<int>ans(n,0) ;
    Node* root = NULL;
    
    for(int i = n-1; i >= 0; i--)
        ans[i] = insert_node(root, arr[i], 0);

    return ans;
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




