




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




class Node
{
    public :
    Node *links[26];//26 small characters
    set<int>indexes ;
    void put(char ch , Node *node1)
    {
        this->links[ch-'a'] = node1 ;
    }
    bool contains(char ch)
    {
        return this->links[ch-'a']!=NULL;
    }
    Node* get(char ch)
    {
        return this->links[ch-'a'];
    }
    void insert(int i)
    {
        this->indexes.insert(i) ;
    }


};

class Trie
{
public:
    Node *root ;
    Trie()
    {
        root = new Node();
    }
    void insert(string word , int index)
    {
        Node* traverse = this->root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!traverse->contains(word[i1]))
                traverse->put(word[i1],new Node());
            
            traverse = traverse->get(word[i1]);
            traverse->insert(index);
        }

    }
    // set<indexes> search(string word)

};



class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        
        Trie *root = new Trie();
    
        sort(contact,contact+n);
        for (int i1 = 0; i1 < n; i1++)
            root->insert(contact[i1] ,i1);
        
        vector<vector<string>> ans1 ;
        Node *traverse = root->root ;
        bool endreach = false ;
        int i1 = 0;
        for (i1 = 0; s[i1] && !endreach; i1++)
        {
            set<string> temp1 ;
            if(traverse->contains(s[i1]))
            {
                traverse = traverse->get(s[i1]);
                set<int> indices = traverse->indexes;
                for(auto ind : indices)
                    temp1.insert(contact[ind]);
                
                vector<string> temp2;
                for(auto x : temp1)
                    temp2.push_back(x);
                ans1.push_back(temp2);
            }
            else 
            {
                ans1.push_back({"0"});
                endreach = true ;
            }
        }
        for(;i1<s.size();i1++)
            ans1.push_back({"0"});
    
        
        return ans1 ;
   
    }
};


