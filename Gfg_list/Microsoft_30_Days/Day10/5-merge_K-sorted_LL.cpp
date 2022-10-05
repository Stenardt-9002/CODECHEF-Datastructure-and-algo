// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day10/problem/merge-k-sorted-linked-lists





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
struct compare_func
{
    bool operator()(struct Node *a1 ,struct Node *b1)
    {
        return a1->data>b1->data ;
    }
};




Node *mergeKLists(Node *arr[], int K)
{
        // Your code here
    priority_queue<Node* , vector<Node*> , compare_func> pq1 ;

    for (int i1 = 0; i1 < K; i1++)
        if(arr[i1]!=NULL)
            pq1.push(arr[i1]);
    
    if(pq1.empty())
        return NULL ;

    struct Node* newdummy = new Node(-1);
    struct Node* last = newdummy ;

    while(!pq1.empty())
    {
        struct Node* cur = pq1.top();
        pq1.pop();

        last->next = cur ;
        last = last->next ;

        if(cur->next!=NULL)
            pq1.push(cur->next);
    }


    return newdummy->next ;
}


