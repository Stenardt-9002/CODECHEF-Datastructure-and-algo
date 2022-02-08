

 struct ListNode {
    int val;
    ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };




class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        
        ListNode *prev,*ne1w,*curr ;
        prev = NULL;ne1w = NULL ;curr = head ;
        
        while(curr!=NULL)
        {
            ne1w = curr->next ;
            curr->next = prev ;
            
            //,move now 
            prev = curr ;
            curr = ne1w ;
            
            
            
        }
        return prev ;
        
        
        
    

    }
};