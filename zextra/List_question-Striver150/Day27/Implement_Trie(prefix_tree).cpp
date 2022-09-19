// https://leetcode.com/problems/implement-trie-prefix-tree/







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

class Node {
    Node *links[26];
    bool flag = false ;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL) ;
    }
    void put(char ch , Node *node)
    {
        links[ch-'a'] = node ;
    }

};

class Trie {
public:

    Node* root  ;

    Trie() {
        
    }
    
    void insert(string word) 
    {
        Node *node = root ;
        for (int i1 = 0; i1 < word.length(); i1++)
        {
            if(node->containsKey(word[i1])!=NULL)
            {

            }
        }
        
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
};

