// https://practice.geeksforgeeks.org/problems/geek-and-strings3030/1
    



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

class Node {
    public:
    Node *links[26]; 
    int endstring = 0 ;
    int prefix_count= 0;
    bool containskey(char ch)
    {
        return links[ch-'a']!=NULL ;
    }
    void put(char ch ,Node *newnode)
    {
        links[ch-'a'] = newnode ;
    }
    Node* get(char c)
    {
        return links[c-'a'];
    }
    void increaseEnd()
    {
        endstring++ ;
    }
    void increasePrefix()
    {
        prefix_count++ ;
    }
    void deleteEnd()
    {
        endstring-- ;
    }
    void reducePrefix()
    {
        prefix_count--;
    }

};

class Trie
{
private:
    Node *root ;
public:
    Trie();
    void insert(string word )
    {
        Node *traverse = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!traverse->containskey(word[i1]) )
                traverse->put(word[i1], new Node() );

            traverse = traverse->get(word[i1]);
            traverse->increasePrefix();
        }
            traverse->increaseEnd();

    }
    int searchprefix(string word)
    {
        Node *traverse = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!traverse->containskey(word[i1]) )
                return 0 ;

            traverse = traverse->get(word[i1]);
        }
        return traverse->prefix_count;
    }

};

Trie::Trie()
{
    this->root = new Node();
}
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
            Trie *node = new Trie();
        for(int i1 = 0 ; i1<N;i1++)
            node->insert(li[i1]);
    
        vector<int> asn1 ; 
    
        for(int i1 = 0 ; i1<Q;i1++)
            asn1.push_back(node->searchprefix(query[i1]));// node->insert(li[i1]);
    
        return asn1 ;

    }

int main(int argc, char const *argv[])
{
    fastIO

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif 


    
    int testcase ;
    // long long int n ;//, target;
    testcase=1 ;
    // cin>>testcase;
    while (testcase--)
    {
        int n,m ;
        cin>>n;
        string *array = new string[n];
        for(int i1 = 0 ; i1< n ; i1++)
            cin>>array[i1];
        cin>>m;
        string *query = new string[m];
        for(int i1 = 0 ; i1< m ; i1++)
            cin>>query[i1];
            
        for(auto it:prefixCount(n,m,array, query))
            cout<<" "<<it ;
        
        cout<<endl;

    }
    return 0 ;
}



