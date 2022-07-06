
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
    Node * next;
    Node * arb;
    Node (int x)
    {
        data=x;
        next=NULL;
        arb=NULL;
    }
        
};



   Node *copyList(Node *head)
    {
        //Write your code here
        // int n = 0 ;
        // Node *cur = head  ;


        // vector<Node *>has_mp(101,NULL);
        // Node *newhead = new Node(head->data);
        // has_mp[head->data] = newhead ; 

        // if(head->arb!=NULL)
        // {
        //     if( has_mp[head->arb->data]==NULL)
        //         has_mp[head->arb->data] = new Node(head->arb->data) ;

        //     newhead->arb = has_mp[head->arb->data];
        // }
        // cur = head->next ;
        // Node *cur2 = newhead  ;

        // while(cur!=NULL)
        // {
        //     if(has_mp[cur->data]==NULL )
        //         has_mp[cur->data] = new Node(cur->data);
        //     cur2->next = has_mp[cur->data];
        //     if(cur->arb!=NULL)
        //     {
        //         if(has_mp[cur->arb->data]==NULL )
        //             has_mp[cur->arb->data] = new Node(cur->arb->data);
        //         cur2->next->arb = has_mp[cur->arb->data];

        //     }

        //     cur = cur->next ; 
        //     cur2 = cur2->next ;
        // }
        
        // return newhead ;


        Node *cur = head  ;
        Node *newhead = new Node(head->data);

        unordered_map<Node* ,Node*> hash_map;
        hash_map[head] = newhead ; 
        if(head->arb!=NULL)
        {
            if(hash_map.find(head->arb)==hash_map.end())
                hash_map[head->arb] = new Node(head->arb->data) ;

            newhead->arb = hash_map[head->arb];
        }
        cur = head->next ;
        Node *cur2 = newhead  ;

        while(cur!=NULL)
        {
            if(hash_map.find(cur)==hash_map.end())
                hash_map[cur] = new Node(cur->data);
            cur2->next = hash_map[cur];
            if(cur->arb!=NULL)
            {
                if(hash_map.find(cur->arb)==hash_map.end())
                    hash_map[cur->arb] = new Node(cur->arb->data);
                cur2->next->arb = hash_map[cur->arb];
            }

            cur = cur->next ; 
            cur2 = cur2->next ;
        }
        
        return newhead ;
    }