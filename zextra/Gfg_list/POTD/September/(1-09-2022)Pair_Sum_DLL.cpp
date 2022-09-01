
// https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};



vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    // code here
    if(head==NULL)
        return {};
    Node *end1 = head ;
    while(end1->next !=NULL)
        end1 = end1->next ;

    vector<pair<int,int>> ans1 ;
    if(head==end1)
        return {};
    
    while(head!=end1 && head!=end1->prev)
    {
        if(head->data + end1->data < target)
            head = head->next ;
        else if(head->data + end1->data > target) 
            end1 = end1->prev ;
        else 
        {
            ans1.push_back({head->data , end1->data});
            head = head->next ;
            end1 = end1->prev ;
        }
    }
    if(head==end1->prev && head->data+end1->data == target)
        ans1.push_back({head->data , end1->data});
    return ans1 ;
}


