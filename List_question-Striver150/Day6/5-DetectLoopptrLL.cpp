#include<iostream>
#include <bits/stdc++.h>
using namespace std;

  
    
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };




    // ListNode *detectCycle(ListNode *head) 
    // {
    //     unordered_set<ListNode*> hash1;
        
    //     while(head!=NULL)
    //     {
    //         if(hash1.find(head)!=hash1.end())
    //         {
    //             return head ;
    //         }
    //             hash1.insert(head);
    //             head = head->next;
    //     }
    //     return NULL ;
        
    // }

// O(n) O(1)

      ListNode *detectCycle(ListNode *head) 
    {
        ListNode* slow1 = head ;
        ListNode* fast1 = head ;
        ListNode* temp1 = head ;
                // temp1//entry point
        if(head == NULL||head->next == NULL) return NULL;
        
        if (head->next==head|| head->next->next==head)
        {
            return head ;
        }
        
        while(fast1->next!=NULL && fast1->next->next!=NULL)
        {
            slow1 = slow1->next ;
            fast1 = fast1->next->next ;
            
            if(slow1==fast1)
            {
                 
                while(temp1!=slow1)
                {
                    temp1 = temp1->next;
                    slow1 = slow1->next;
                }
                return temp1;
            }
        }
            
        
        return NULL ;
        

    }




