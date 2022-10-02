#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    struct Node* next;
    Node(char x){
        data = x;
        next = NULL;
    }
};
bool search_1(Node *cur , Node *manager,char &answer , char search)
{
    cur = manager->next ;
    if(cur->next->data == search)
    {
        answer = cur->data ;
        return true ;
    }
    cur = cur->next ;
    while(cur!=manager->next)
    {
        if(cur->next->data == search)
        {
            answer = cur->data ;
            return true ;
        }
        cur = cur->next ;
    }
    return false ;
} 

int main()
{
    // Node *manager1 = new Node('\0') ;
    // Node *cur = new Node('X') ;
    // manager1->next = cur ;
    // cur->next = new Node('T');
    // cur->next->next = new Node('V');
    // cur->next->next->next = new Node('W');
    // cur->next->next->next->next = new Node('U');
    // cur->next->next->next->next->next = new Node('C');
    // cur->next->next->next->next->next->next = new Node('S');
    // cur->next->next->next->next->next->next->next = new Node('B');
    // cur->next->next->next->next->next->next->next->next = new Node('R');
    // cur->next->next->next->next->next->next->next->next->next = new Node('A');
    // cur->next->next->next->next->next->next->next->next->next->next = manager1->next ;



    Node *manager1 = new Node('\0') ;
    Node *cur = new Node('X') ;
    manager1->next = cur ;
    cur->next = new Node('T');

    cur = cur->next;
    cur->next = new Node('V');

    cur = cur->next;
    cur->next = new Node('W');

    cur = cur->next;
    cur->next = new Node('U');

    cur = cur->next;
    cur->next = new Node('C');

    cur = cur->next;
    cur->next = new Node('S');

    cur = cur->next;
    cur->next = new Node('B');

    cur = cur->next;
    cur->next = new Node('R');

    cur = cur->next;
    cur->next = new Node('A');

    cur = cur->next;
    cur->next = manager1->next ;
    //circular 

    int i1 = 0;
    cur = manager1->next;
    // cout<<"DEUG";
    // while(i1++<12)
    // {
    //     cout<<" "<<cur->data ;
    //     cur = cur->next ;
    // }

    char input1 ;
    while(true)
    {
        cout<<endl ;
        cin>>input1 ;
        if(input1=='-')
            break ;
        
        char output ;
        cur = manager1->next ;
        if(search_1(cur , manager1, output , input1))
            cout<<endl<<input1<<" is backup for "<<output ;
        else 
            cout<<"\nNo employee named "<<input1 ;

    }


}

