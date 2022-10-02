// https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/?ref=lbp


#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val ;
        left = right = NULL;
    }
} ;
 

class LiNode
{
    
public:
    int data ;
    LiNode* next ;
    LiNode(int val)
    {
        data = val ;
        next = NULL ;
    }
};


void push(LiNode* ptr,int val)
{
    while (ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new LiNode(val);
}

void printList(LiNode *temp1)
{
    cout<<endl ;
    while (temp1!=NULL)
    {
        cout<<" "<<temp1->data ;temp1 = temp1->next ;
    }cout<<endl;
}


int countNode(LiNode *temp)
{
    int n = 0;
    while (temp!=NULL)
    {
        temp = temp->next;
        n++;
    }
    return n;
}

Node* sortTedListoBST(LiNode **temp1,int n)
{
    if (n<=0)
        return NULL;
    Node *left = sortTedListoBST(temp1,n/2);

    Node *root = new Node((*temp1)->data);
    root->left = left ;

    *temp1 = (*temp1)->next ;
    
    root->right = sortTedListoBST(temp1,n-n/2-1);
    return root ;

}


Node* sortedtoBST(LiNode *temp1)
{
    int n = countNode(temp1);
    return sortTedListoBST(&temp1,n);
}


int main(int argc, char const *argv[])
{
    LiNode *head = new LiNode(7) ;
    push(head,6);
    push(head,5);
    push(head,4);
    push(head,3);
    push(head,2);
    push(head,1);


    // cout<<head->data<<" "<<head->next->data ;

    Node *root = sortedtoBST(head);

    return 0;
}



 
    // int countNode(LNode *temp1)
    // {
    //     int n = 0; while(temp1!=NULL){temp1 = temp1->next ; n++;}
    //     return n;
    // }
  
  
    // TNode* sortedListFuc(LNode **head,int n) 
    // {
    //     if(n<=0)
    //         return NULL ;
            
    //     TNode *left1 =  sortedListFuc(head,n/2);
        
    //     TNode *root = new TNode((*head)->data);
    //     root->left = left1 ;
        
    //     *head = (*head)->next;
        
    //     root->right = sortedListFuc(head,n-n/2 -1);
    //     return root ;
        
        
    // }
  
    // TNode* sortedListToBST(LNode *head) 
    // {
    //     int n = countNode(head) ;
    //     return sortedListFuc(&head,n);
    // }