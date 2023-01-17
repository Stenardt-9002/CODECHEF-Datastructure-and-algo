// https://practice.geeksforgeeks.org/problems/da62a798bca208c7a678c133569c3dc7f5b73500/1









#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;




struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

class Solution {
public:


    Node *merge(Node *head1 , Node *head2 )
    {
        if(head1==NULL)
            return head2 ;

        if(head2==NULL)
            return head1 ;

        if(head1->data<=head2->data)
        {
            head1->bottom = merge(head1->bottom,head2 );
            return head1 ;
        }
        head2->bottom = merge(head2->bottom,head1 );
        return head2 ;

    }


    Node *flatten(Node *root)
    {
        // Your code here


        if(root==NULL || root->next==NULL)
            return root ;
        return merge(flatten(root->next),root);


        // Node* trav = root ;
        // while (trav!=NULL)
        // {
        //     Node* temp = trav;
        //     while (trav->bottom!=NULL)
        //     {
        //         //insert 
        //         Node *move = trav->bottom ;
        //         trav->bottom = trav->bottom->bottom ;
        //         while (!(temp->next==NULL|| temp->next->data>move->data ))
        //             temp = temp->next ;

        //         move->bottom = NULL ;
        //         move->next = temp->next ;
        //         temp->next = move ;
        //     }
        //     trav->next ;
        // }
        


        return root ;

    }
};

















