#include<iostream>
using namespace std;

  
  
  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };





 ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow1 = head ;
        ListNode* fast1 = head ;
        
        while(fast1 && fast1->next !=NULL && fast1->next->next!=NULL)
        {
            slow1 = slow1->next ;
            fast1 = fast1->next->next ;
            
        }
        if(fast1->next!=NULL)
        {
            slow1 = slow1->next;
        }
        return slow1;
    }




//another approach Count to N


