#include<iostream>
using namespace std;

  
    
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
    
        int cunt1 = 0 ;
//         int asn1 = 0;
//         while(l1!=NULL)
//         {
//              asn1+= ((l1->val)*pow(10,cunt1));
//             cunt1++;
//         }
//         cunt1 =0;
//         while(l2!=NULL)
//         {
//              asn1+= ((l2->val)*pow(10,cunt1));
//             cunt1++;
//         }
        
//         ListNode* ans12 = new ListNode();
//         ListNode* return2 = ans12 ;
//         while(asn1!=0)
//         {
//             ans12->val = asn1%10 ;
//             asn1/=10;
//             ListNode* temp1 = new ListNode()    ;
//             ans12->next = temp1;
//             ans12 = temp1 ;
//         }
//         ans12 = NULL ;
//         return return2 ;
        
         
        ListNode* ans12 = new ListNode();
        ListNode* origans12 = ans12;
        int ans ;
        int carry = 0;
        while(l1!=NULL && l2!=NULL)
        {
            
            ListNode* temp1 = new ListNode();
            ans12->next = temp1 ;
            ans12 = ans12->next ;
            
            
            ans = l1->val+l2->val+carry ;
            
            if (ans>9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            ans12->val = ans%10 ;
            
          
            l1 = l1->next ;
            l2 = l2->next ;
            cunt1++;
        }
        
        if(l1==NULL && l2==NULL)
        {
            if (carry ==1)
            {
                ListNode* temp1 = new ListNode();
                ans12->next = temp1 ;
                ans12 = ans12->next ;
                ans12->val = carry ;
                ans12->next = NULL ;
            }
            else
            {
            // printf("Reached here");
            //     cout<<cunt1 ;
                ans12->next = NULL ;
                
                
            }
            return origans12->next ;
        }
        
        
        else if(l1==NULL)
        {
            //code only for l1 to have larger number and go forward
            std::swap(l1,l2);
        }
        
        
        while(l1!=NULL)
        {
            ListNode* temp1 = new ListNode();
            ans12->next = temp1 ;
            ans12 = ans12->next ;
            
            
            
            ans = l1->val+carry ;
            if (ans>9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            ans12->val = ans%10 ;
          
            l1 = l1->next ;
            
        }
           if (carry ==1)
            {
                ListNode* temp1 = new ListNode();
                ans12->next = temp1 ;
                ans12 = ans12->next ;
                ans12->val = carry ;
                ans12->next = NULL ;
            }
            else
            {
            // printf("Reached here");
            //     cout<<cunt1 ;
                ans12->next = NULL ;
                
                
            }
            return origans12->next ;
        
        
    }



int main(int argc, char const *argv[])
{

    int snas1 = 10;
    cout<<(snas1<<1);


    ListNode* vaar1 = new ListNode();
    ListNode* vaar2 = new ListNode();
    vaar1->val = 2 ;
    vaar2->val = 5 ;

    vaar1=vaar1->next = new ListNode();
    vaar2=vaar2->next = new ListNode();
    
    vaar1->val = 4 ;
    vaar2->val = 6 ;

    vaar1=vaar1->next = new ListNode();
    vaar2=vaar2->next = new ListNode();
    
    vaar1->val = 3 ;
    vaar2->val = 4 ;

vaar1 = NULL ;
vaar2 = NULL ;

    // vaar1=vaar1->next = new ListNode();
    // vaar2=vaar2->next = new ListNode();
    
    ListNode* ans1 = addTwoNumbers(vaar1,vaar2) ;
    cout<<ans1->val ;



    return 0;
}


