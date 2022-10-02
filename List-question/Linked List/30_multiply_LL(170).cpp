// https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long ll1d;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
int MOD1 = 1000000007 ;



// long long  multiplyTwoLists (Node* l1, Node* l2)
// {
//   //Your code here
//     stack<Node*> s1 ;
//     stack<Node*> s2 ;
//     while(l1!=NULL)
//         s1.push(l1), l1 = l1->next;

//     while(l2!=NULL)
//         s2.push(l2), l2 = l2->next;
         
//     long long int ans1 = 0 ;
//     long long int val1 = 0;
//     long long int pow = 1;
//     int data1,data2 ;
//     while (!s1.empty()&& !s2.empty())
//     {
//         data1 = s1.top()->data ;
//         data2 = s2.top()->data ;
//         s1.pop() ; s2.pop();
        
//         ans1 += (data1)*pow ;
//         val1 += (data2)*pow ;
//         pow *= 10;
//     }

//     while(!s1.empty())
//     {
//         data1 = s1.top()->data ;
//         ans1 += (data1)*pow ;
//         pow *= 10 ;
//         s1.pop() ;
//     }
    
//     while(!s2.empty())
//     {
//         data1 = s2.top()->data ;
//         val1 += (data1)*pow ;
//         pow *= 10 ;
//         s2.pop() ;
//     }
    
//     return (val1*ans1)%MOD1 ;
// }



long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
         
    long long int ans1 = 0 ,val1 = 0;
    while (l1!=NULL || l2!=NULL)
    {
        if(l1)
        {
            ans1 = ((ans1)*10)%MOD1 + l1->data ;
            l1 = l1 -> next ;
        }
        if(l2)
        {
            val1 = ((val1)*10)%MOD1 + l2->data ;
            l2 = l2 -> next ;
        }
    }
    
    return ((val1%MOD1)*(ans1%MOD1))%MOD1 ;
}




