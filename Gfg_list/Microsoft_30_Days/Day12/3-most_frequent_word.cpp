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
    Node *links[26];
    int isleaf_count = 0 ;
    int prefix_count = 0;
    int first_index_occur = -1;
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
    void increment_prefix()
    {
        this->prefix_count++ ;
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
            traverse->increment_prefix();
        }
        traverse->at_end();
        int ans1 = traverse->isleaf_count;
        if(traverse->first_index_occur==-1)
            traverse->first_index_occur=index ;
        int index_ans = traverse->first_index_occur ;
        return {index_ans , ans1};
    }

};

Trie::Trie()
{
    root = new Node();
}



string mostFrequentWord(string arr[], int n) 
{
    // code here
    Trie* start = new Trie();
    int most_count = 0 ;
    int ans1_index = 0 ;
    string ans1 = arr[0];
    for (int i1 = 0; i1 < n; i1++)
    {
        pair<int,int > out = start->insert(arr[i1],i1);
        if(most_count<out.second || (most_count==out.second && ans1_index<out.first))
        {
            ans1 = arr[i1];
            most_count = out.second ;
            ans1_index = out.first ;
        }
    }
    return ans1 ;
}

// https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/2599448/C%2B%2B-or-DP-or-Related-Problems

// 62. Unique Paths
// 70. Climbing Stairs
// 509. Fibonacci Number
//  639. Decode Ways II.



