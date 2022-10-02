#include<iostream>
#include<cmath>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    long long int daat1;
    long long int daat2;
    struct node * next;
    
};

struct node *head = NULL;
// (struct node*)(malloc(sizeof(struct node)));

int main(int argc, char const *argv[])
{
    long long int n,i,sqrt1,asn;
    cin>>n;
    sqrt1=sqrt(n);
    sqrt1 = sqrt1+1;
    struct node *top = head;
    cout<<'\n'<<sqrt1;
    for (size_t i = 2; i < sqrt1; i++)
    {
        if (n%i==0)
        {
            struct node *dtaa = (struct node*)(malloc(sizeof(struct node)));
            dtaa->daat1 = i;
            asn = n/i;
            dtaa->daat2 = asn;
            dtaa->next = NULL;
            if (top==NULL)
            {
                top = dtaa;
                head = top;
            }
            else
            {
            top->next = dtaa;
            
            }
        }
    }

    cout<<"Reached";
    //print
    struct node *tmp = head;

    while (tmp!=NULL)
    {
        cout<<endl;
        cout<<tmp->daat1<<"  "<<tmp->daat2;
        tmp = tmp->next;
    }
    
    
   return 0; 
    
   
}

