
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<string>
using namespace std;

// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

    class Node
    {
        public :
        int data ;
        Node *next ;
        Node *prev ;

        Node(int data)
        {
            this->data = data ;
            prev = next = NULL ;
        }
    };


class Stack
{
public:
    Node* head = NULL ;
    Node* mid = NULL ;
    int cursize = 0;

    void push(int data)
    {
        Node *temp = new Node(data);
        if (cursize==0)
        {
            head = temp ;
            mid = temp ;
            cursize++ ;      
        }
        else
        {
            head->next = temp ;
            temp->prev = head ;
            head = head->next ;


            if (cursize%2==1)
                mid = mid->next ;   

            cursize++ ;     
        }
        
    }

    void pop()
    {
        if (cursize>0)
        {
            if (cursize==1)
            {
                head = NULL ; mid = NULL ;
            }
            else
            {
                head = head->prev ;
                head->next = NULL ;
                if (cursize%2==0)
                    mid = mid->prev ;

                                
            }
            cursize--;
        }

    }

    int findMiddle()
    {
        if(cursize==0)
            return -1;

        return mid->data ;
    }
    
    void deleteMiddle()
    {
        if(cursize!=0)
        {
            if (cursize==1)
            {
                head = NULL ; mid = NULL ;
            }
            else if (cursize==2)
            {
                head = head->prev ; mid = mid->prev ; 
                head->next = NULL ;
            }
            else
            {
                mid->next->prev = mid->prev ; 
                mid->prev->next = mid->next ;
                
                if (cursize%2==0)
                    mid = mid->prev ;
                    //was even 
                else 
                    mid = mid->next ;
            }
            cursize--;
        }
    }


};


