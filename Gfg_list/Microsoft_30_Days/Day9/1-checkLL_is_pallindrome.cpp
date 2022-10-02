// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day9/problem/check-if-linked-list-is-pallindrome



#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int mod1 = (1e9+7);
const int MOD1 = 1000000007;

const long long int mod2 =  1e18 ;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

bool isPalindrome(Node *head)
{
    //Your code here

    Node *fast = head ;
    Node *slow = head ;
    while(fast!=NULL && fast->next!=NULL)
        fast = fast->next->next , slow=slow->next ;

    Node *cur = slow ;
    Node *prev = NULL;
    Node *nextNode = NULL ;
    while(cur!=NULL)
    {
        nextNode = cur->next ;
        cur->next = prev ;
        prev = cur ;
        cur = nextNode ;
    }
    while(prev!=NULL)
    {
        if(prev->data!=head->data)
            return false ;
        prev = prev->next ;
        head = head->next ;

    }
    return true ;

}







