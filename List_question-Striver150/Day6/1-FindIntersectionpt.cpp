#include<iostream>
using namespace std;

  
    
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
    
        int count1=0 ,count2=0 ;
        ListNode* ptr1 = headA ,*ptr2 = headB ;
        while(ptr1!=NULL)
        {
            count1++;ptr1 = ptr1->next ;
        }
        while(ptr2!=NULL)
        {
            count2++;ptr2 = ptr2->next ;
        }
        
        ptr1 = headA ;ptr2 = headB ;
        
        if (count1<count2)
        {
            std::swap(ptr1,ptr2);
        }
        
        int diff = abs(count1-count2) ;
        
        
        while(diff-->0)
        {
            ptr1 = ptr1->next ;
        }
        
        while(ptr1!=ptr2&& ptr1!=NULL &&ptr2!=NULL)
        {
            ptr1 = ptr1->next ; ptr2 = ptr2->next ;
         
        }
        
           if(ptr1==ptr2)
            {
                return ptr1;
            }
        return NULL;
        
        
        
        
        
        
        
        
        
    }

















