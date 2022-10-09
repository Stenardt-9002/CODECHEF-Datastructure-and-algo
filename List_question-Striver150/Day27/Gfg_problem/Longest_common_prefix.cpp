// https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1






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
class Node
{

public:
    Node* lins[26];
    int countprefix=0;
    int endwith = 0 ;
    
    bool containskey(char ch);
    void put(char ch , Node *node);
    Node *get(char cg);
    void incrteaseEnd();
    void IncreasePrefix();
    // void deleteEnd();
    // void redcueEnd();

};

bool Node::containskey(char ch)
{
    return (this->lins[ch-'a']!=NULL);
}
void Node::put(char ch , Node *node)
{
    this->lins[ch-'a'] = node ;
}

Node* Node::get(char ch )
{
    return this->lins[ch-'a'] ;
}
void Node::incrteaseEnd()
{
    this->endwith++ ;
}

void Node::IncreasePrefix()
{
    this->countprefix++ ;
}
class Trie
{
    
public:
    Node *root ;
    Trie();

    void insert(string word)
    {
        Node *trav = root;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!trav->containskey(word[i1]))
                trav->put(word[i1] , new Node());

            trav = trav->get(word[i1]);//moving to refrence trie
            trav->IncreasePrefix();
        }
        trav->incrteaseEnd();//set end 
       
    }
    bool search(string word , int length)
    {
        Node *node = root ;
        for (int i = 0; word[i]; i++)
        {
            if(!node->containskey(word[i]))
                return false ;
            
            node = node->get(word[i]);
        }
        return node->countprefix == length ;

    }

};

Trie::Trie()
{
    root = new Node();
}


    
string longestCommonPrefix (string arr[], int N)
{
    // your code here
            string longestword = "";
        Trie *var = new Trie();
        for(int i1=0 ;i1<N;++i1)
        {
            var->insert(arr[i1]);
            if(arr[i1].length()>longestword.length())
                longestword = arr[i1];
        }
        string ans1 = "";
        for (int i1 = 0; longestword[i1]; i1++)
            if(var->search(longestword.substr(0,i1+1),N ))
                ans1+=longestword[i1];
            else 
                break ;
        
        return ans1.size()==0?"-1":ans1 ;
}



