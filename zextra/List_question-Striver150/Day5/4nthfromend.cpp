
#include<iostream>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
    
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* early=start ,*ahead1=start;
        int count1 = 0;
        
        if(head->next==NULL && n==1)
        {
            return NULL;
        }
        
        while(ahead1->next!=NULL)
        {
            
            
            if(++count1>n)
            {
                early = early->next ;
                
            }
            ahead1 = ahead1->next;
            
        }
  
        if(early->next!=NULL)
        {
               
        early->next = early->next->next;
        }
        
        return start->next ;
        
    }
