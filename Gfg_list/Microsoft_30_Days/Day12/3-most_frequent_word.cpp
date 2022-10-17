// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day12/problem/most-frequent-word-in-an-array-of-strings3528



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
    int isleaf_count = 0 ;//words ending here
    int first_index_occur = -1;//the word ending here first index occurrence
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
    void at_end()
    {
        this->isleaf_count++ ;
    }


};

class Trie
{
public:
    Node *root ;
    Trie();
    pair<int,int> insert(string word , int index)
    {
        Node* traverse = this->root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!traverse->contains(word[i1]))
                traverse->put(word[i1],new Node());
            
            traverse = traverse->get(word[i1]);
        }
        traverse->at_end();

        //set index of first occurrence of the word
        if(traverse->first_index_occur==-1)
            traverse->first_index_occur=index ;
        int index_ans = traverse->first_index_occur ;
        int ans1 = traverse->isleaf_count;
        return {index_ans , ans1};
        // the index first occurrence , number of time occurrence
    }

};

Trie::Trie()
{
    root = new Node();
}



// string mostFrequentWord(string arr[], int n) 
string findWord(vector<string> arr) 
{
    // code here
    int n = arr.size();
    Trie* root = new Trie();
    int most_count = 0 ;//maintain the count of the word
    int ans1_index = 0 ;//index of the word of first occurrence
    string ans1 = arr[0];
    for (int i1 = 0; i1 < n; i1++)
    {
        pair<int,int > insert_data = root->insert(arr[i1],i1);
        if(most_count<insert_data.second || (most_count==insert_data.second && ans1_index<insert_data.first))
        {
            ans1 = arr[i1];
            most_count = insert_data.second ;
            ans1_index = insert_data.first ;
        }
    }
    return ans1 ;
}

int main()
{
    vector<string> arr{ "geeks",    "for",     "geeks",
                        "a",        "portal",  "to",
                        "learn",    "can",     "be",
                        "computer", "science", "zoom",
                        "yup",      "fire",    "in",
                        "be",       "data",    "geeks" };
    string sol = findWord(arr);
    // Print word having highest frequency
    cout << sol << endl;
}




