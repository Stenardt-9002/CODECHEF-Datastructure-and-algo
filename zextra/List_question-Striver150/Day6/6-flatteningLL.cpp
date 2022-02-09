#include<iostream>
using namespace std;

  
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


// Node* Inser1(Node * start1,int insert1)
// {
//     Node* original1 = start1;

//     while (start1->next!=NULL && start1->next->data < insert1)
//     {
//         start1 = start1->next;
//     }
//     Node* temp1 = new Node(insert1);
//     temp1->next = start1->next;
//     start1->next = temp1;

//     return original1 ;
// }

    
Node* Inser1(Node * start1,int insert1)
{
    
    
    Node* original1 = start1;
    if(start1->data>insert1)
    {
        Node *temp2 = new Node(insert1);
        temp2->bottom = start1 ;
        temp2->next = start1->next ;
        return temp2;
    }

    while (start1->bottom!=NULL && start1->bottom->data < insert1)
    {
        start1 = start1->bottom;
    }
    Node* temp1 = new Node(insert1);
    temp1->bottom = start1->bottom;
    start1->bottom = temp1;

    return original1 ;
}



Node *flatten(Node *root)
{
   

   Node* dummy = root ;

    while (dummy->next!=NULL)
    {
        while (dummy->next->bottom!=NULL)
        {
            dummy = Inser1(dummy,dummy->next->bottom->data);
            dummy->next->bottom = dummy->next->bottom->bottom;
        }
        
        dummy = Inser1(dummy,dummy->next->data);
        dummy->next = dummy->next->next;


    }
    return dummy;
   
}

void print12(Node *temp1)
{
    cout<<endl;
    while (temp1!=NULL)
    {
        cout<<" "<<temp1->data<<" ";
        temp1= temp1->bottom;
    }
    cout<<endl;
    
}



int main(int argc, char const *argv[])
{
    Node* temp1 = new Node(5);

    Node* temp2 = new Node(10);

    Node* temp3 = new Node(19);

    Node* temp4 = new Node(7);
    Node* temp5 = new Node(8);
    Node* temp6 = new Node(30);
    Node* temp7 = new Node(22);



     temp1->next = temp2 ;
     temp2->next = temp3;
     temp3->next = new Node(28) ;

     temp1->bottom = temp4; 
     temp4->bottom = temp5;
     temp5->bottom = temp6 ;

     temp3->bottom = temp7;


    cout<<"\nPrint  "<<temp1->next->data;
    print12(temp1);
    temp1 = Inser1(temp1,6);
    cout<<"\nPrint  "<<temp1->next->data;
    print12(temp1);



    Node* dummy = temp1->next ;
       while (dummy->bottom!=NULL)
        {
            Inser1(temp1,dummy->bottom->data);
            dummy->bottom = dummy->bottom->bottom;
            
        }
        Inser1(temp1,dummy->data);
    
    // flatten(temp1);

    cout<<"\nPrint  "<<temp1->next->data;


    print12(temp1);




    return 0;
}





