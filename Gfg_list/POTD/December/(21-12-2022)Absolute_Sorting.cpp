// https://leetcode.com/problems/cherry-pickup/







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
    Node* next;
    int data;
}; 

class Solution
{
    public:
    Node* sortList(Node* head)
    {
        if(head==NULL||head->next==NULL)
            return head ;
        Node *dummy = new Node;
        dummy->next = head ;
        Node *pointr = head;
        while (pointr->next!=NULL)
        {
            if(pointr->next->data<0)
            {
                Node *temp = pointr->next ;
                pointr->next = pointr->next->next ;
                temp->next = dummy->next;
                dummy->next = temp ;
            }
            else 
                pointr = pointr->next ;
        }
        
        return dummy->next ;
    }
};