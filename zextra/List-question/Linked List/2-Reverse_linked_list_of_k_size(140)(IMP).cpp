    // https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};


    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL || k==1)
        return head ;

        struct node* answer1 = new node(24)  ; // original head
        answer1->next = head ; 
        struct node* n2 = answer1 ;
        struct node* cur = answer1 ;
        struct node* prev = answer1 ;
        int length1 =0;
        while(cur->next!=NULL)
            length1++ , cur = cur->next ;
    
        // cur = head ; 
        for(int i1 = 0 ; i1<length1/k ; i1++)
        {
            cur = prev->next ;
            n2 = cur->next ;
            for (int j1 = 0; j1 < k-1; j1++)
            {
    
                cur->next = n2->next  ;
                n2->next = prev->next ;
                prev->next = n2 ;
                n2 = cur->next ;
            }
            prev = cur ;
        }
        // cout<<"length"<<length1 ;
        if(length1%k!=0)
        {
            cur = prev->next ;
            n2 = cur->next ;
            for (int j1 = 0; j1 < (length1%k)-1; j1++)
            {
                cur->next = n2->next  ;
                n2->next = prev->next ;
                prev->next = n2 ;
                n2 = cur->next ;
            }
            prev = cur ;
        }
        
        return answer1->next ;
    }