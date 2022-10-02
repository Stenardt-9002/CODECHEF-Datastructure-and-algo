#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };



ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


            if(list1==NULL)
        {
            return list2 ;
        }
        if(list2==NULL)
        {
            return list1;
        }
        
        ListNode* temp1 ;
        
        if(list1->val>list2->val)
        {
            std::swap(list1,list2);
        }
        ListNode* ans1  = list1;
        
        while(list1!=NULL && list2!=NULL)
        {
            
            temp1 = list1;
            while(list1!=NULL && list1->val<=list2->val)
            {
                temp1 = list1;
                list1 = list1->next;
            }
            
            if(list2!=NULL)
            {
                temp1->next = list2 ;    
            }
            
            std::swap(list1,list2);
            
        }
        return ans1;
        



}