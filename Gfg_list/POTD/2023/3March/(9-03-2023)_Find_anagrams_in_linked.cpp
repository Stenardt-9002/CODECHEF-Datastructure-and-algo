












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








struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};
class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) 
    {
        // code here    
        if(head==NULL)
            return {};
        int k = s.length();
        if(k==0)
            return {};
        vector<int> hash_s(26,0),current_hash(26,0);
        vector<Node *>ans ;
        for(int i1 = 0 ; i1<k;i1++)
            hash_s[s[i1]-'a']++;

        int i = k ;
        Node *secondptr = head ,*firstptr = head ; 
        Node *last_prev = NULL ;
        while(secondptr!=NULL && i--)
        {
            current_hash[secondptr->data -'a']++;
            last_prev = secondptr ;
            secondptr = secondptr->next ;
        }

        while(secondptr!=NULL)
        {
            if(current_hash==hash_s)    
            { 
                ans.push_back(firstptr)        ;
                firstptr = secondptr ;
                last_prev->next = NULL ;
                for(int in = 0 ; in <26;++in)
                    current_hash[in] = 0;
                i = k ;
                while(secondptr!=NULL && i--)
                {
                    current_hash[secondptr->data -'a']++;
                    last_prev = secondptr ;
                    secondptr = secondptr->next ;
                }
            }
            else 
            {
                current_hash[firstptr->data-'a']-- ; 
                current_hash[secondptr->data-'a']++ ; 
                firstptr = firstptr->next ; 
                last_prev = secondptr ;
                secondptr = secondptr->next ;
            }
        }
        
        if(current_hash==hash_s)    
            ans.push_back(firstptr);
        return ans ;
    }
};
