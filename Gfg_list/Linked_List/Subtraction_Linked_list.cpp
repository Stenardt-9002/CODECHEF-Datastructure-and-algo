


// https://practice.geeksforgeeks.org/problems/subtraction-in-linked-list/1?page=1&difficulty[]=2&status[]=unsolved&category[]=Graph&sortBy=submissions



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

void reverse_util(Node* &l1)
{
    if(l1==NULL)
        return ;
    Node *current = l1 ;
    Node *prev = NULL ,*nextptr = NULL;
    while (current!=NULL)
    {
        nextptr = current->next ;
        current->next = prev ;
        prev = current ;
        current = nextptr ;
    }
    l1 = prev ;
}

bool subtract_util(Node* l1 , int n1 , Node* l2 , int n2 , Node* &ans)
{
    int carry = 0 ;
    Node *final_ans = new Node(-1);
    Node *rta = final_ans ;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->data-carry>=l2->data)
        {
            rta->next = new Node(l1->data-carry-l2->data);
            carry = 0;
        }
        else 
        {
            rta->next = new Node(l1->data+10-carry-l2->data);
            carry = 1;
        }
        rta = rta->next ;
        l1 = l1->next ;
        l2 = l2->next ;
    }
    while(l1!=NULL)
    {
        if(l1->data>=carry)
        {
            rta->next = new Node(l1->data-carry);
            carry = 0;
        }
        else 
        {
            rta->next = new Node(l1->data+10-carry);
            carry = 1;
        }
        rta = rta->next ;
        l1 = l1->next ;
    }
    if(carry)
        return false ;
    
    ans = final_ans->next ;
    final_ans->next = NULL ;
    delete final_ans ;
    // cout<<"DEbug \n";
    return true ;
}

//You are required to complete this method

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    int n1 = 0 , n2 = 0 ;

    Node *anms = NULL ;
    while(l1!=NULL && l1->data == 0)
        l1 = l1->next ;
    while(l2!=NULL && l2->data == 0)
        l2 = l2->next ;
    Node* tra = l1 ;
    if(l1==NULL)
        return l2 ;
    if(l2==NULL)
        return l1 ;
    while (tra!=NULL)
    {
        n1++ ;
        tra = tra->next ;
    }
    tra = l2 ;
    while (tra!=NULL)
    {
        n2++ ;
        tra = tra->next ;
    }
    // cout<<"DEbug1 \n";

    if(n1<n2)
    {
        tra = l1 ; 
        l1 = l2 ;
        l2 = tra ;
        swap(n1 , n2);
    }
    reverse_util(l1);
    reverse_util(l2);


    if(!subtract_util(l1 , n1 , l2 , n2 , anms))
        subtract_util(l2 , n2 , l1 , n1 , anms);

    reverse_util(anms);
    while(anms!=NULL && anms->data==0)
        anms = anms->next ;
    if(anms==NULL)
        return new Node(0);
    return anms ;
}
// 9
// 0 7 1 5 3 6 1 0 7
// 9
// 0 7 1 5 3 6 1 0 7






// 7
// 5 0 3 7 3 6 2
// 6
// 0 6 3 5 1 5
int main()
{
    // Node *linked_lost = new Node(0);
    // linked_lost->next = new Node(7);
    // linked_lost->next->next = new Node(1);
    // linked_lost->next->next->next = new Node(5);
    // linked_lost->next->next->next->next = new Node(3);
    // linked_lost->next->next->next->next->next = new Node(6);
    // linked_lost->next->next->next->next->next->next = new Node(1);
    // linked_lost->next->next->next->next->next->next->next = new Node(0);
    // linked_lost->next->next->next->next->next->next->next->next = new Node(7);




    // Node *linked_lost1 = new Node(0);
    // linked_lost1->next = new Node(7);
    // linked_lost1->next->next = new Node(1);
    // linked_lost1->next->next->next = new Node(5);
    // linked_lost1->next->next->next->next = new Node(3);
    // linked_lost1->next->next->next->next->next = new Node(6);
    // linked_lost1->next->next->next->next->next->next = new Node(1);
    // linked_lost1->next->next->next->next->next->next->next = new Node(0);
    // linked_lost1->next->next->next->next->next->next->next->next = new Node(7);


    Node *linked_lost = new Node(5);
    linked_lost->next = new Node(0);
    linked_lost->next->next = new Node(3);
    linked_lost->next->next->next = new Node(7);
    linked_lost->next->next->next->next = new Node(3);
    linked_lost->next->next->next->next->next = new Node(6);
    linked_lost->next->next->next->next->next->next = new Node(2);




    Node *linked_lost1 = new Node(0);
    linked_lost1->next = new Node(6);
    linked_lost1->next->next = new Node(3);
    linked_lost1->next->next->next = new Node(5);
    linked_lost1->next->next->next->next = new Node(1);
    linked_lost1->next->next->next->next->next = new Node(5);



    Node *ans = subLinkedList(linked_lost1 , linked_lost);
    return 0 ;
}