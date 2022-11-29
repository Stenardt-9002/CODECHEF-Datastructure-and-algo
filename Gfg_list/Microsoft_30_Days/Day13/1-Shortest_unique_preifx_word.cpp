// https://practice.geeksforgeeks.org/batch/microsdaysoft-29/track/microsoft-29days-day13/problem/shortest-unique-prefix-for-every-word


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



class Node
{
public:
    Node *links[26]   ;
    int prefix_count = 0 ;
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

    void increase_prefix()
    {
        this->prefix_count++ ;
    }
    int get_prefix()
    {
        return this->prefix_count ;
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
    void insert(string word)
    {
        Node *traversal = root ;
        for (int i1 = 0; word[i1]; i1++)
        {
            if(!traversal->containskey(word[i1]))
                traversal->put(word[i1], new Node());

            traversal = traversal->get(word[i1]);
            traversal->increase_prefix();
        }
        traversal->end();
    }


    string get_min_string(string word)
    {
        Node *traversal = root ;
        string ans1 = "";
        for (int i1 = 0; word[i1]; i1++)
        {
            if(traversal->get_prefix()==1 || !traversal->containskey(word[i1]))
                return ans1 ;
            traversal = traversal->get(word[i1]);
            ans1+=word[i1];
            if(traversal->get_prefix()==1)
                return ans1 ;
        }
        return word ;
    }

};







vector<string> findPrefixes(string arr[], int n)
{
    //code here
    Trie *root = new Trie();
    for(int i1= 0;i1<n;++i1)
        root->insert(arr[i1]);

    vector<string> answer ;
    for(int i1= 0;i1<n;++i1)
        answer.push_back(root->get_min_string(arr[i1]));
    return answer ;

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
        string *input1 = new string[n];
        for (int i1 = 0; i1 < n; i1++)
            cin>>input1[i1] ;
        
        vector<string> output = findPrefixes(input1,n);
        for(auto out:output)
            cout<<out<<" ";
    }
    return 0 ;
}

