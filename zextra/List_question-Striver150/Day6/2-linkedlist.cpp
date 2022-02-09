#include<iostream>
using namespace std;

  
    
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };



// #uses hashing
// 


    // bool hasCycle(ListNode *head) 
    // {
    //     unordered_set<ListNode *> s1;
    //     while(head!=NULL)
    //     {
    //         if(s1.find(head)!=s1.end())
    //             return true;
            
    //         s1.insert(head);
    //         head = head->next ;
    //     }
        
    //     return false ;
    // }



bool hasCycle(ListNode *head)
{
    if (head==NULL)
    return false;

    ListNode* slow = head ;
    ListNode *fast = head ;

    while (fast->next!=NULL && fast->next->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast==slow)
        {
            return true;
        }
        

    }
    return false;



}









