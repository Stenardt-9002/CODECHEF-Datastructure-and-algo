
// https://practice.geeksforgeeks.org/problems/length-of-longest-palindrome-in-linked-list/1


#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;
typedef  long long int ll;
#define DEBUG_var 1


struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int maxPalindrome(Node *head)
{
    //Your code here
    stack<int>orginal ;
    if(head==NULL)
        return 0 ;
    if(head->next==NULL)
        return 1 ;
    int ans1 = 1 ;
    int counter1 =0  ;
    int counter2 =1  ;

    while (head!=NULL &&head->next!=NULL)
    {
        orginal.push(head->data);
        stack<int>copy1 = orginal ;
        counter1 = 0 ;
        Node *cur1 = head ;
        
        while(!copy1.empty()&&cur1->next!=NULL&& (copy1.top() == cur1->next->data))
        {
            copy1.pop();
            cur1 = cur1->next;
            counter1+=2 ;
        }
        ans1 = max(ans1,counter1);


        cur1 = head ;
        counter2 = 1 ;
        while(!copy1.empty()&&cur1->next!=NULL&& cur1->next->next!=NULL&& (copy1.top() == cur1->next->next->data))
        {
            copy1.pop();
            cur1 = cur1->next;
            counter2+=2 ;
        }

        ans1 = max(ans1,counter2);


        head = head->next ;
    }
    return ans1 ;
}




int main(int argc, char const *argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int n ;
    cin>>n;
    int *arr1 = new int[n];
    Node *head1 = new Node(-1) ;
    Node *cur1 =head1 ;
    for (int i1 = 0; i1 < n; i1++)
    {
        cin>>arr1[i1]    ;
        cur1->next = new Node(arr1[i1]);
        cur1 = cur1->next ;

    }

    cur1 = head1->next;
    // while(cur1!=NULL)
    //     cout<<cur1->data<<" " ,cur1 = cur1->next ;
    // cout<<endl<<kthElement( arr1, arr2 , n, m, k);
    cout<<" "<<maxPalindrome(cur1);
    cout<<"\n";
    return 0;
}



