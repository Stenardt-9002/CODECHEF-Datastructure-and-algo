// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

// Node* partition(Node *l, Node *h)
// {
//         //Your code goes here

//     if(l==NULL || l->next == h)
//         return l ;
//     Node *cur = l ;
//     while(cur!=h&&cur!=NULL)
//     {
//         if(cur->data > h->data)
//         {
//             Node *righttemp = h->next ;
//             Node *cur_node1;
//             if(cur->prev!=NULL)
//                 cur_node1 = cur->prev->next ;
//             else 
//                 cur_node1 = cur->next->prev ;

//             if(cur->prev!=NULL)
//                 cur->prev->next = cur->next ;
//             if(cur->next!=NULL)
//                 cur->next->prev = cur->prev;

//             h->next = cur_node1 ;
//             cur_node1->prev = h ;
//             cur_node1->next = righttemp ;
//             righttemp->prev = cur_node1 ;
//         }
//         else 
//             cur = cur->next ;
//     }
//     return h ;
// }



Node* partition(Node *l, Node *h)
{
        //Your code goes here
        int x = h->data ;
        Node *i1 = l->prev ;
    
        for(auto j = l ; j!=h ; j = j->next)
            if(j->data<=x)
            {
                if(i1!=NULL)
                    i1 = i1->next ;
                else 
                    i1 = l ;
                // i1 = (i1==NULL)? l : i1->next ;
                swap(&(i1->data), &(j->data));
            }
        if(i1!=NULL)
            i1 = i1->next ;
        else 
            i1 = l ;
        // i1 = (i1==NULL)?l:i1->next ;
        swap(&(i1->data), &(h->data));
        return i1 ;

}



