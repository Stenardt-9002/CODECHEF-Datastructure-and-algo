


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





    ListNode *moveToFront(ListNode *head)
    {
        if(head->next==NULL)    
            return head ;

        ListNode* ptr = head ;
        while(ptr->next->next!=NULL)
            ptr = ptr->next ;
        
        ListNode *newhead = ptr->next ;
        ptr->next = NULL ;
        newhead->next = head ;
        
        return newhead ;
        
    }