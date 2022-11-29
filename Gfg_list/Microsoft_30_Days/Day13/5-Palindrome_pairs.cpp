// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day13/problem/palindrome-pairs





#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds ;


typedef vector<int> vi ;
typedef vector<vi> vii ;

const int mod1 = (1e9+7);
const long long int mod2 =  1e18 ;

#define mii map<int,int> 
#define msi map<string,int> 
#define musi unordered_map<string,int> 

typedef  long long int lld;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool ispallindrome(string str , int start , int end )
{
    while(start<end)
    {
        if(str[start]!=str[end])
            return false ;
        start++ , end-- ;
    }
    return true;
}

class Node
{
public:
    Node *links[26]   ;
    vector<int>palindrome_pos ;
    int orig_ind ;
    bool end_flag= false ;
    Node *get(char c)
    {
        return links[c-'a'];
    }
    void put(char key , Node *node )
    {
        this->links[key-'a'] = node ;
    }
    bool containskey(char key)
    {
        return this->links[key-'a']!=NULL ;
    }

    void set_index(int set_index)
    {
        this->orig_ind = set_index;
    }

    void end()
    {
        this->end_flag = true ;
    }
};


class Trie 
{
    Node *root = new Node();
    public:
    void insert(string word,int index)
    {
        Node *traversal = root ;
        int len1 = word.size()-1;
        for (int i1 = len1; i1>=0; i1--)
        {
            if(!traversal->containskey(word[i1]))
                traversal->put(word[i1], new Node());

            if(ispallindrome(word , 0 , i1))
                (traversal->palindrome_pos).push_back(index);

            traversal = traversal->get(word[i1]);
        }
        traversal->set_index(index);
        (traversal->palindrome_pos).push_back(index);
        traversal->end();
    }


    void search(string word, int index , vector<vector<int>>& result)
    {
        Node *traversal = root ;
        int len1 = word.length();
        for (int i1 = 0; i1<len1; i1++)
        {
            if(traversal->orig_ind>=0 && traversal->orig_ind!=index && ispallindrome(word ,i1,len1-1 ))
                result.push_back({index , traversal->orig_ind});



            if(!traversal->containskey(word[i1]))
                return ;

            traversal = traversal->get(word[i1]);
        }
        for(int i : traversal->palindrome_pos)
        {
            if(i!=index)
                result.push_back({index , i});
        }
    }

};










bool palindromepair(int N, string arr[]) 
{
    // code here
    Trie *root = new Trie();
    for (int i1 = 0; i1 < N; i1++)
    root->insert(arr[i1],i1);

    vector<vector<int>>ans1 ; 

    for (int i1 = 0; i1 < N; i1++)
    {
        root->search(arr[i1],i1,ans1);
        if(ans1.size()>0)
            return true ;
    }
    return false ;

    
}





