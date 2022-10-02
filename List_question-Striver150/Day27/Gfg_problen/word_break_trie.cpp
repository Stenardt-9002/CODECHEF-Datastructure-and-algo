// https://practice.geeksforgeeks.org/problems/d857113143f69fab217cf5dab978535542f3cbb1/1


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
    public : 
    Node* links[26];
    bool flag = false ;
    bool contatinsKey(char ch)
    {
        return this->links[ch-'a']!=NULL ;
    }
    void put(char ch , Node *newconnect)
    {
        this->links[ch-'a'] = newconnect;
    }
    Node *get(char ch)
    {
        return this->links[ch-'a'];
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
        void insert(string word)
        {
            Node *trav = root ;
            for (int i1 = 0; word[i1]; i1++)
            {
                if(!trav->contatinsKey(word[i1]))
                    trav->put(word[i1] , new Node());

                trav = trav->get(word[i1]);
            }
            trav->flag = true ;
        }
        pair<bool,bool> search(string word)
        {
            Node *trav = root ;
            for (int i1 = 0; word[i1]; i1++)
            {
                if(!trav->contatinsKey(word[i1]))
                    return {false , false} ;

                trav = trav->get(word[i1]);
            }
            return {true,trav->flag}  ;
            //first if false means no such sentence ending with no letter
            //second means word ending
        }
};

bool funcok(string a , Trie *var , int start)
{
    if(start==a.length())
        return true ;
    bool ans1 = false ;
    bool nosuchword = false ;
    string suchword = "";
    int i1 = 0;
    for (i1 = start; a[i1] && !nosuchword; i1++)
    {
        suchword+=a[i1];
        if((var->search(suchword)).first &&(var->search(suchword)).second)
            ans1 = ans1||funcok(a,var,i1+1);

        else if(!(var->search(suchword)).first)
                nosuchword=true ;

    }
    return ans1 ;    
}



int wordBreak(string A, vector<string> &B) 
{
    //code here
    Trie *var = new Trie();
    for(auto str : B)
        var->insert(str);
    
    return funcok(A , var , 0);


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
    // testcase=1 ;
    cin>>testcase;
    while (testcase--)
    {
        int n ;
        cin>>n;
        vector<string> input1(n) ;
        for (int i1 = 0; i1 < n; i1++)
            cin>>input1[i1] ;
        
        string output ;
        cin>>output ;
        cout<<wordBreak(output , input1)<<endl;
    }
    return 0 ;
}
