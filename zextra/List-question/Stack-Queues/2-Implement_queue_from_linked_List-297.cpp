




#include <bits/stdc++.h>
using namespace std;
 

class QNode
{
public:

    int data ; 
    QNode *next ;
    QNode(int d)
    {
        data = d ; 
        next = NULL ;
    }
};






class MyQueue 
{

public :
    QNode *front;
    QNode *rear;

    MyQueue(){front=NULL;rear=NULL;}
    void enqu(int x)
    {
        QNode* temp = new QNode(x) ;
        if (this->rear==NULL)
        {
            this->front = temp ; 
            this->rear = temp ;
        }
        else
        {
            this->rear->next = temp ;
            this->rear = temp ;
        }
    }
    int deque()
    {
        if (this->front == NULL )
            return -1 ; //empty

        QNode* tobedel = this->front ;
        this->front  = this->front->next ; 

        if (this->front == NULL )
            this->rear = NULL ; //empty now
        int data = tobedel->data ;
        delete(tobedel)         ;
        return data ;

    }
    void print() 
    {
        QNode* temp = this->front ;
        while (temp!=NULL)
        {
            cout<<" "<<temp->data ;
            temp = temp->next ;
        }
        cout<<endl ;
        
    }
};


int main(int argc, char const *argv[])
{
    MyQueue q1 ;

    q1.enqu(10) ;
    q1.print() ;
    q1.enqu(20) ;
    q1.print() ;
    q1.enqu(50) ;
    q1.print() ;
    q1.deque();
    q1.print() ;
    q1.deque();
    q1.print() ;
    q1.deque();
    q1.print() ;
    q1.enqu(60) ;
    q1.print() ;
    q1.enqu(70) ;
    q1.print() ;




    return 0;
}

