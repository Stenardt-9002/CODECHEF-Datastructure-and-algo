#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// int recursive(Node *cur, stack<Node*> &s1 , stack<Node*> &s2)
// {
//     Node* cur ;
//     if(!s1.empty()&&!s2.empty())
//     {
//         Node* first = s1.top();
//         s1.pop();
//         Node* second = s2.top();
//         s2.pop();


//     }

//     int carry=1;
//     if(cur->next!=NULL)
//         carry = recursive(cur->next);

//     cur->data+=carry ;
//     if(cur->data>=10)
//     {
//         cur->data=cur->data%10;
//         return 1 ;
//     }
//     return 0 ;

// }




struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    if(first==NULL)
        return second ;
    if(second==NULL)
        return first ;
    stack<Node*> s1 ;
    stack<Node*> s2 ;
    Node *cur = first ;

    while(cur!=NULL)
    {
        s1.push(cur);
        cur = cur->next ;
    }

   cur = second ;

    while(cur!=NULL)
    {
        s2.push(cur);
        cur = cur->next ;
    }
    Node *ans1=NULL  ;
    int carry = 0;
    while(!s1.empty()&&!s2.empty())
    {
        Node* first = s1.top();
        s1.pop();
        Node* second = s2.top();
        s2.pop();
        Node *cur_ans = NULL ;
        int cur_data=first->data+second->data+carry;
        if(cur_data>9)
            carry = 1;
        else 
            carry = 0 ;

        cur_ans = new Node(cur_data%10);
        cur_ans->next = ans1 ;
        ans1 = cur_ans ;

    }

    while(!s1.empty())
    {
        Node* first = s1.top();
        s1.pop();
        Node *cur_ans = NULL ;
        int cur_data=first->data+carry;
        if(cur_data>9)
            carry = 1;
        else 
            carry = 0 ;

        cur_ans = new Node(cur_data%10);
        cur_ans->next = ans1 ;
        ans1 = cur_ans ;
    }
    while(!s2.empty())
    {
        Node* second = s2.top();
        s2.pop();
        Node *cur_ans = NULL ;
        int cur_data=second->data+carry;
        if(cur_data>9)
            carry = 1;
        else 
            carry = 0 ;
        cur_ans = new Node(cur_data%10);
        cur_ans->next = ans1 ;
        ans1 = cur_ans ;
    }
    if (carry==1)
    {
        Node *cur_ans = NULL ;
        cur_ans = new Node(1);
        cur_ans->next = ans1 ;
        ans1 = cur_ans ;
    }
    return ans1 ;
}


