// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day10/problem/add-two-numbers-represented-by-linked-list




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


struct Node {
	int data;
	struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL ;
    }
};


Node* addSameSize(Node* head1, Node* head2, int* carry) 
{ 
	// Your code here
	    stack<int> s1,s2;

    while (head1!=NULL && head2!=NULL)
    {
        s1.push(head1->data);
        s2.push(head2->data);
        head1 = head1->next;
        head2 = head2->next;
    }
    int carry_temp = 0;
    Node *ans1 = NULL;

    while (!s1.empty() && !s2.empty())
    {
        int temp = carry_temp+s1.top()+s2.top();
        s1.pop();
        s2.pop();
        carry_temp = temp/10 ;
        temp = temp%10 ;
        Node *nodetemp = new Node(temp);
        nodetemp->next = ans1 ;
        ans1 = nodetemp ;
        // cout<<"\nDEUG  " <<temp;
    }
    *carry = carry_temp ;
    return ans1 ;

} 


//This function is called after the smaller list is added to the sublist of 
//bigger list of same size. Once the right sublist is added, the carry
//must be added to left side of larger list to get the final result.
void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) 
{ 
	// Your code here
    if(head1->next != curr)
	    addCarryToRemaining(head1->next, curr, carry, result);
	
	else if(head1->next == curr)
	    head1->next = *result;
	
	head1->data += *carry;
	*carry = head1->data / 10;
	head1->data %= 10;
	*result = head1;
	
}



int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 

    Node *head1 = new Node(9);
    head1->next = new Node(7);
    head1->next->next = new Node(3);


    Node *head2 = new Node(2);
    head2->next = new Node(7);

    
    int testcase ;
    // long long int n ;//, target;
    testcase=1 ;
    // cin>>testcase;
    while (testcase--)
    {
        // cin>>n;
        int car = 0;
        Node *ans1 = addSameSize(head1,head2,&car);
        cout<<endl;
        cout<<car<<" "<<ans1->data<<" "<<ans1->next->data;
    }
    return 0 ;
}


