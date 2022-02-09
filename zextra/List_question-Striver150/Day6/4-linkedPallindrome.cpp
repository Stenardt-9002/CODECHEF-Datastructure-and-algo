#include<iostream>
using namespace std;

  
    
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };








     ListNode* reverseList1(ListNode* head1 ) 
     {
         ListNode* prev1 = NULL;
         ListNode* curr1 = head1;
         ListNode* next1 = NULL ;
         
         
         while(curr1!=NULL)
         {
             next1 = curr1->next ;
             curr1->next = prev1;
             
             //move now
             prev1 = curr1;
             curr1 = next1;
                          
                                       
         }
         
         return prev1;
         
     }
    
    
    
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL||head->next==NULL)return true ;
        
       //getting middle
        
        ListNode* slow1 = head ;
        ListNode* fast1 = head ;
        
        
        while(fast1->next!=NULL && fast1->next->next!=NULL)
        {
            slow1 = slow1->next ;
            fast1 = fast1->next->next;
            
        }
        
       
                       
        slow1->next = reverseList1(slow1->next);
        
        ListNode *orignmiddle = slow1->next;
        //reverse after middle
        
        // now check first part and second part simultaneously 
        while(orignmiddle!=NULL)
        {
            
            if(head->val!=orignmiddle->val)
            {
                return 0;
            }
            
            head = head->next;
            orignmiddle = orignmiddle->next;
        }
        return 1 ;
        
    
        
        
    }





    bool isPalindrome(ListNode* head) 
    {
    
        stack<int>s1 ;
        ListNode* tra = head ;
        
        while(tra!=NULL)
        {
            s1.push(tra->val);
            tra = tra->next ;
            
        }
        
        tra= head ;
        while(tra!=NULL)
        {
            if(tra->val != s1.top())
            {
                return 0 ;
            }
            tra = tra->next ;
            s1.pop();
        }
        return 1;
        
        
    }





