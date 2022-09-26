//    https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day10/problem/remove-all-occurences-of-duplicates-in-a-linked-list



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
   struct Node {
	int data;
	struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL ;
    }
};



   Node* removeAllDuplicates(struct Node* head)
    {
        //code here
        if(head==NULL)
            return NULL;
        Node * ptr = head ;
        while(ptr->next!=NULL && ptr->data == ptr->next->data)
            ptr = ptr->next;
        if(ptr!=head)
            return removeAllDuplicates(ptr->next);
        bool dupl_found = false ;
        while(ptr->next!=NULL && ptr->next->next!=NULL)
        {
            if(ptr->next->data == ptr->next->next->data)
            {
                int temp_data = ptr->next->data;
                Node *temp = ptr->next;
                while(temp!=NULL && temp->data == temp_data)
                    temp = temp->next ;
                ptr->next = temp ;
                
            }
            else 
                ptr = ptr->next ;
            
        }
        return head ;
    }