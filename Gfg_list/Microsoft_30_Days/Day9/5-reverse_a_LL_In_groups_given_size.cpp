// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day9/problem/reverse-a-linked-list-in-groups-of-given-size



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
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};


struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    node *prev = NULL ;
    node *cur = head ;
    node* nextnode = NULL ;
    int count11 = 0 ;
    while (count11++<k && cur!=NULL)
    {
        nextnode = cur->next ;
        cur->next = prev ;
        prev = cur ;
        cur = nextnode;
    }
    if(nextnode!=NULL)
        head->next = reverse(nextnode , k);
    return prev ;
}


