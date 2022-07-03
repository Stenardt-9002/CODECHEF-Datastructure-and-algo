// https://leetcode.com/problems/middle-of-the-linked-list/submissions/

#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head ;
        ListNode *slow = head ;
        ListNode *fast = head ;
        while(fast!=NULL)
        {
            fast = fast->next ;
            if(fast!=NULL)
            {
                slow = slow->next ;
                fast = fast->next ;
            }
        }
        return slow ;
    }