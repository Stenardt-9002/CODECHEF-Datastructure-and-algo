


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
    public:
    Node *links[26];
    int countendwith = 0 ;
    int countwithprefix = 0 ;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL) ;
    }
    void put(char ch , Node *node)
    {
        links[ch-'a'] = node ;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    } 
    void increaseEnd()
    {
        countendwith++ ;
    }
    void increasePrefix()
    {
        countwithprefix++ ;
    }
    void deleteEnd()
    {
        countendwith-- ;
    }
    void reducePrefix()
    {
        countwithprefix--;
    }

};


class Trie {
public:

    Node* root  ;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) 
    {
        Node *node = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!node->containsKey(word[i1]))
                node->put(word[i1] , new Node());

            node = node->get(word[i1]);//moving to refrence trie
            node->increasePrefix();
        }
        node->increaseEnd();//set end 
        
    }
    
    int countWordsEqualTo(string word) 
    {
        Node *node = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!node->containsKey(word[i1]))
                return 0;

            node = node->get(word[i1]);
        }
        return node->countendwith ;
    }
    int countWordStartingWith(string word) 
    {
        Node *node = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!node->containsKey(word[i1]))
                return 0;

            node = node->get(word[i1]);
        }
        return node->countwithprefix ;
    }
    void erase(string word) 
    {
        //asumming the word exist
        Node *node = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!node->containsKey(word[i1]))
                return ;

            node = node->get(word[i1]);//moving to refrence trie
            node->reducePrefix();
        }
        node->deleteEnd();//set end 
        
    }
    
};


